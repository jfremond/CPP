/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:17:36 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/28 18:39:13 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>					_data;
		std::map<std::string, double>::const_iterator	_it;
		int												_error;
		double											_stod(std::string const &to_cast);
		void											_fillData();
		int												_checkDateValidity(std::string date);
		int												_checkLine(std::string date, std::string delim, std::string value);
		int												_parseFile(std::string const &filename);
		void											_printRes(int error, std::string date, std::string value);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const &filename);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();
};

BitcoinExchange::BitcoinExchange() : _error(0)
{
	_fillData();
	_parseFile("input.txt");
}

BitcoinExchange::BitcoinExchange(std::string const &filename) : _error(0)
{
	_fillData();
	_parseFile(filename);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _data(src._data), _it(src._it), _error(src._error)
{
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	_data = rhs._data;
	_it = rhs._it;
	_error = rhs._error;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

double	BitcoinExchange::_stod(std::string const &to_cast)
{
	std::stringstream	stream;
	double				res;
	
	stream << to_cast;
	stream >> res;
	if (stream.fail())
		_error = 1;
	return (res);
}

void	BitcoinExchange::_fillData()
{
	std::ifstream	db;
	std::string		line;
	std::string		ac;
	std::string		bc;
	size_t			comma;

	db.open("data.csv");
	if (!db)
	{
		std::cout << "Error: cannot open file."	<< std::endl;
		return ;
	}
	else
	{
		while (!db.eof())
		{
			getline(db, line);
			comma = line.find(",");
			bc = line.substr(0, comma);
			ac = line.substr(comma + 1, line.length());
			if (!db.eof() && ac != "exchange_rate")
			_data.insert(std::pair<std::string, double>(bc, _stod(ac.c_str())));
		}
	}
}

int	BitcoinExchange::_checkDateValidity(std::string date)
{
	std::string	year;
	std::string	mon;
	std::string day;

	if (date.length() != 10)
		_error = 2;
	if (_error == 0 && (date[4] != '-' || date[7] != '-'))
		_error = 2;
	year = date.substr(0, 4);
	date.erase(0, year.length());
	date.erase(0, 1);
	mon = date.substr(0, 2);
	date.erase(0, mon.length());
	date.erase(0, 1);
	day = date.substr(0, 2);
	date.erase(0, day.length());
	if (_error == 0 && (year < "2009" || year > "2022"))
		_error = 2;
	if (_error == 0 && (mon < "01" || mon > "12"))
		_error = 2;
	if (_error == 0 && (day < "01" || day > "31"))
		_error = 2;
	if (_error == 0 && (_stod(year) <= 2009 && _stod(mon) <= 1 && _stod(day) <= 2))
		_error = 2;
	return (_error);
}


int	BitcoinExchange::_checkLine(std::string date, std::string delim, std::string value)
{
	_checkDateValidity(date);
	_it = _data.upper_bound(date);
	--_it;
	if (_error == 0 && delim != " | ")
		_error = 3;
	if (_error == 0 && _stod(value) < 0)
		_error = 4;
	if (_error == 0 && _stod(value) > 1000)
		_error = 5;
	return (_error);
}


int	BitcoinExchange::_parseFile(std::string const &filename)
{
	std::ifstream	file;
	std::string		line;
	std::string		date;
	std::string		delim;
	std::string		value;

	file.open(filename.c_str());
	if (!file)
	{
		std::cout << "Error: cannot open file" << std::endl;
		return (1);
	}

	while (!file.eof())
	{
		getline(file, line);
		if (!file.eof())
		{
			if (line != "date | value")
			{	
				date = line.substr(0, 10);
				line.erase(0, date.length());
				delim = line.substr(0, 3);
				line.erase(0, delim.length());
				value = line.substr(0, line.length());
				line.erase(0, value.length());
				_checkLine(date, delim, value);
				_printRes(_error, date, value);
			}
		}
		_error = 0;
	}
	return (0);
}

void	BitcoinExchange::_printRes(int error, std::string date, std::string value)
{
	switch (error)
	{
		case 1:
			std::cout << "Error: convertion has failed." << std::endl;
			break;
		case 2:
			std::cout << "Error: bad input => " << date << std::endl;
			break;
		case 3:
			std::cout << "Error: delimitor is invalid." << std::endl;
			break;
		case 4:
			std::cout << "Error: not a positive number." << std::endl;
			break;
		case 5:
			std::cout << "Error: too large a number." << std::endl;
			break;	
		default:
			std::cout << date << " => " << value << " = " << _stod(value) * _it->second << std::endl;
			break;
	}
}


#endif
