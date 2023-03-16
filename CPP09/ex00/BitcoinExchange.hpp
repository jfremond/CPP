/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:28:30 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/16 06:09:27 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <list>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_data;
		std::list<std::string>			_date;
		std::list<double>				_value;
		BitcoinExchange();
	public:
		BitcoinExchange(std::string const filename);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();
		void	fillData();
		void	printData();
		void	fillList(std::string filename);
		void	printList();
};

BitcoinExchange::BitcoinExchange()
{
	fillData();
	std::cout << "Default constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string const filename)
{
	fillData();
	fillList(filename);
	std::cout << "String constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _data(src._data)
{
	std::cout << "Copy constructor" << std::endl;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	_data = rhs._data;
	std::cout << "Assignment operator overload" << std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor" << std::endl;
}

void	BitcoinExchange::fillData()
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
		if (!db.eof())
			_data.insert(std::pair<std::string, double>(bc, atof(ac.c_str())));
	}
	_data.erase("date");
}

void	BitcoinExchange::printData()
{
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
		std::cout << "date: " << it->first << "\t" << "exchange_rate: " << it->second << std::endl;
	std::cout << "size: " << _data.size() << std::endl;
}

void	BitcoinExchange::fillList(std::string filename)
{
	std::ifstream	file;
	file.open(filename.c_str());
	if (!file)
	{
		std::cout << "Error: cannot open file" << std::endl;
		return ;
	}
	std::string		line;
	std::string		bp;
	std::string		ap;
	size_t			pipe;

	while (!file.eof())
	{
		getline(file, line);
		pipe = line.find("|");
		bp = line.substr(0, pipe - 1);
		std::cout << "bp: " << bp << "\t\t";
		if (pipe != std::string::npos)
		{
			ap = line.substr(pipe + 2, line.length());
			std::cout << "ap: " << ap << std::endl;
		}
		// if (!bp.empty())
		// else
		// 	std::cout << "bp: empty" << std::endl;
		// if (!ap.empty())
		// else
		// 	std::cout << "ap: empty" << std::endl;
		if (!file.eof())
		{
			if (!bp.empty())
				_date.push_back(bp);
			if (!ap.empty())
			_value.push_back(atof(ap.c_str()));
		}
	}
}

void	BitcoinExchange::printList()
{
	for (std::list<std::string>::iterator it = _date.begin(); it != _date.end(); it++)
		std::cout << "date: " << *it << std::endl;
	for (std::list<double>::iterator it = _value.begin(); it != _value.end(); it++)
		std::cout << "value: " << *it << std::endl;
	std::cout << "size of _date: " << _date.size() << "\t" << "size of _value: " << _value.size() << std::endl;
}

#endif
