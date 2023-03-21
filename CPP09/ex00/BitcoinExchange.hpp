/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:28:30 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/21 17:37:46 by jfremond         ###   ########.fr       */
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
		std::map<std::string, double>	_data;
		//! Rename bool because it covers all errors
		bool							_stream_error;
		//& Convert a string to a double
		double							_stod(std::string str_to_cast);
		//& Convert a double to a string
		std::string						_dtos(double val_to_cast);
		void							_fillData();
		void							_printRes();
		BitcoinExchange();
	public:
		BitcoinExchange(std::string const filename);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();
		void	printData();

};

//--------------- PRIVATE FUNCTIONS ----------------//

double	BitcoinExchange::_stod(std::string str_to_cast)
{
	std::stringstream	stream;
	double				res;

	stream << str_to_cast;
	stream >> res;
	
	if (stream.fail())
	{
		std::cout << str_to_cast << std::endl;
		std::cout << "Error: stringstream has failed" << std::endl;
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
		_stream_error = true;
		std::cout << "Error: stringstream has failed" << std::endl;
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

void	BitcoinExchange::_printRes()
{
	std::ifstream	file;
	std::string		line;
	file.open("input.txt");
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
	std::cout << "Header is valid" << std::endl;
	while (!file.eof())
	{
		getline(file, line);
		if (!file.eof())
		{	
			std::string s1 = line.substr(0, 10);
			//& Function to check date validity here
			std::cout << "[" << s1 << "]" << "\t";
			line.erase(0, s1.length());
			std::string	s2 = line.substr(0, 3);
			//& Function to check separator validity here
			std::cout << "[" << s2 << "]" << "\t";
			line.erase(0, s2.length());
			std::string s3 = line.substr(0, line.length());
			//& Function to check value validity here
			std::cout << "[" << s3 << "]" << std::endl;	
		}
	}
}

BitcoinExchange::BitcoinExchange() : _stream_error(false)
{
	_fillData();
	std::cout << "Default constructor" << std::endl;
}

//--------------- PUBLIC FUNCTIONS ----------------//

BitcoinExchange::BitcoinExchange(std::string const filename) : _stream_error(false)
{
	(void)filename;
	_fillData();
	_printRes();
	std::cout << "String constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _data(src._data), _stream_error(src._stream_error)
{
	std::cout << "Copy constructor" << std::endl;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	_data = rhs._data;
	_stream_error = rhs._stream_error;
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
