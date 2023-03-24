/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:28:30 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/23 19:14:56 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>	//ifstream
#include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		std::map<std::string, double>					_data;
		std::map<std::string, double>::const_iterator	it;
		int												_error;
		double											_stod(std::string str_to_cast);
		std::string										_dtos(double val_to_cast);
		void											_fillData();
		void											_printRes(std::string const filename);
		int												_checkDateValidity(std::string str);
	public:
		BitcoinExchange(std::string const filename);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();
		void	printData();
};

//--------------- PRIVATE FUNCTIONS ----------------//

BitcoinExchange::BitcoinExchange() : _error(0)
{
	_fillData();
	std::cout << "Default constructor" << std::endl;
}

double	BitcoinExchange::_stod(std::string str_to_cast)
{
	std::stringstream	stream;
	double				res;

	stream << str_to_cast;
	stream >> res;
	
	if (stream.fail())
	{
		_error = 1;
		// std::cout << str_to_cast << std::endl;
		// std::cout << "Error: stringstream has failed" << std::endl;
	}
	return (res);
}

std::string	BitcoinExchange::_dtos(double val_to_cast)
{
	std::stringstream	stream;
	std::string			res;

	//& Add value to stream object
	stream << val_to_cast;
	//& Read from stream object
	stream >> res;
	
	if (stream.fail())
	{
		_error = 1;
		// std::cout << "Error: stringstream has failed" << std::endl;
	}
	return (res);
}

void	BitcoinExchange::_fillData()
{
	std::ifstream	db("data.csv");
	std::string		line;
	std::string		bc;
	std::string		ac;
	size_t			comma;

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

void	BitcoinExchange::_printRes(std::string const filename)
{
	std::ifstream	file;
	std::string		line;
	file.open(filename.c_str());
	if (!file)
	{
		std::cout << "Error: cannot open file" << std::endl;
		return ;
	}
	
	getline(file, line);
	std::string s1 = line.substr(0, 4);
	if (s1 != "date")
		std::cout << "Error: invalid header date" << std::endl;
	line.erase(0, s1.length());
	std::string	s2 = line.substr(0, 3);
	if (s2 != " | ")
		std::cout << "Error: invalid header delim" << std::endl;
	line.erase(0, s2.length());
	std::string s3 = line.substr(0, line.length());
	if (s3 != "value")
		std::cout << "Error: invalid header value" << std::endl;
	int i = 1;
	while (!file.eof())
	{
		getline(file, line);
		if (!file.eof())
		{	
			std::string s1 = line.substr(0, 10);
			_checkDateValidity(s1);
			// std::cout << _error << "\t";
			// std::cout << s1 << "\t";
			try
			{
				it = _data.upper_bound(s1);
				it--;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
			line.erase(0, s1.length());
			std::string	s2 = line.substr(0, 3);
			if (_error == 0 && s2 != " | ")
				_error = 3;
			line.erase(0, s2.length());
			std::string s3 = line.substr(0, line.length());
			// std::cout << s3 << "\t";
			// std::cout << _error << "\t";
			if (_error == 0 && _stod(s3) < 0)
				_error = 4;
			if (_error == 0 && _stod(s3) > 1000)
				_error = 5;
			// std::cout << _error << "\t";
			if (_error == 2)
				std::cout << "Error: bad input => " << s1 << std::endl;
			if (_error == 3)
				std::cout << "Error: delimitor is invalid" << std::endl;
			if (_error == 4)
				std::cout << "Error: not a positive number." << std::endl;
			if (_error == 5)
				std::cout << "Error: too large a number." << std::endl;
			else if (_error == 0)
				std::cout << s1 << " => " << s3 << " = " << _stod(s3) * it->second << std::endl;
		}
		++i;
		_error = 0;
	}
}

int	BitcoinExchange::_checkDateValidity(std::string str)
{
	std::string	tmp = str;
	std::string	y;
	std::string	m;
	std::string d;
	// std::cout << str[4] << " " << str[7] << " " << std::endl;
	if (tmp.length() != 10)
	{
		_error = 2;
		// std::cout << "wrong length" << std::endl;
		return (1);
	}
	else if (str[4] != '-' || str[7] != '-')
	{
		_error = 2;
		// std::cout << "wrong delim" << std::endl;
		return (1);
	}
	y = tmp.substr(0, 4);
	if (y < "2009" || y > "2022")
	{
		// std::cout << y << std::endl;
		_error = 2;
		return (1);
		// std::cout << y << std::endl;
		// std::cout << "wrong date" << std::endl;
	}
	tmp.erase(0, y.length());
	tmp.erase(0, 1);
	m = tmp.substr(0, 2);
	if (m < "01" || m > "12")
	{
		// std::cout << m << std::endl;
		_error = 2;
		return (1);
		// std::cout << m << std::endl;
		// std::cout << "wrong month" << std::endl;
	}
	tmp.erase(0, m.length());
	tmp.erase(0, 1);
	d = tmp.substr(0, 2);
	if (d < "01" || d > "31")
	{
		_error = 2;
		return (1);
		// std::cout << d << std::endl;
		// std::cout << "wrong day" << std::endl;
	}
	if (_stod(y) <= 2009 && _stod(m) <= 1 && _stod(d) <= 2)
	{
		_error = 2;
		return (1);
		// std::cout << "tmp: " << str << std::endl;
		// std::cout << "Date too early" << std::endl;
	}
	// std::cout << y << " " << m << " " << d << " " << str << std::endl;
	return (0);
}


//--------------- PUBLIC FUNCTIONS ----------------//

BitcoinExchange::BitcoinExchange(std::string const filename) : _error(0)
{
	_fillData();
	std::cout << "String constructor" << std::endl;
	_printRes(filename);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _data(src._data), _error(src._error)
{
	std::cout << "Copy constructor" << std::endl;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	_data = rhs._data;
	_error = rhs._error;
	std::cout << "Assignment operator overload" << std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor" << std::endl;
}

void	BitcoinExchange::printData()
{
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
		std::cout << "date: " << it->first << "\t" << "exchange_rate: " << it->second << std::endl;
	std::cout << "size: " << _data.size() << std::endl;
}

#endif
