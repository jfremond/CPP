/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:31:18 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/07 20:32:29 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define ORANGE	"\033[38;2;255;165;0m"

#define ERR_ARG_NUM "Error: wrong number of arguments"
#define ERR_OPN_FIL "Error: cannot open file"
#define ERR_NEG_NUM "Error: not a positive number"
#define ERR_NUM_LIM "Error: number too large"
#define ERR_BAD_INP "Error: bad input"

#include <iostream>
#include <list>
#include <fstream>

class BitcoinExchange
{
	private:
		std::string				_filename;
		//!The database
		std::list<std::string>	_db_date;
		std::list<float>		_db_price;
		//!The input file
		std::list<std::string>	_date;
		std::list<int>			_value;
		BitcoinExchange();
	public:
		BitcoinExchange(std::string const filename);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();
		//! Can call this function even with no class instantied
		static int	print_error(std::string error);
		class CannotOpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (ERR_OPN_FIL);
				}
		};
};

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string const filename) : _filename(filename)
{
	std::ifstream	db("database.csv");
	std::string		buffer;
	std::string		bc;
	std::string		ac;
	size_t			comma;
	while (!db.eof())
	{
		getline(db, buffer);
		comma = buffer.find(",");
		bc = buffer.substr(0, comma);
		ac = buffer.substr(comma + 1, buffer.length());
		size_t space = ac.find(" ");
		ac = ac.substr(space + 1, ac.length());
		std::cout << "bc: " << bc << "\t\t";
		std::cout << "ac: " << ac << std::endl;
	}
	// std::ifstream	ifs(_filename.c_str());
	// //! Can't differenciate if file exist or if i have the rights to open/read it
	// //! Allows to check if directory is passed as a parameter
	// ifs.open(_filename.c_str(), std::ifstream::in);
	// if (!ifs || !ifs.good())
	// 	throw CannotOpenFileException();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _filename(src._filename), _date(src._date), _value(src._value)
{
	std::cout << "Copy constructor" << std::endl;
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	std::cout << "Assignment operator overload" << std::endl;
	if (this != &rhs) {	
		_filename = rhs._filename;
		_date = rhs._date;
		_value = rhs._value;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

int	BitcoinExchange::print_error(std::string error)
{
	std::cout << RED << error << RESET << std::endl;
	return (1);
}

#endif