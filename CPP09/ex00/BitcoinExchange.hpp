/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:02:48 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/01 18:55:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <stdexcept>
#include <iostream>
#include <iomanip>
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
		void											_checkDateValidity(std::string date);
		void											_checkLine(std::string date, std::string const &delim, std::string const &value);
		void											_printRes(std::string const &date, std::string const &value);
		void											_parseFile(std::string const &filename);
		BitcoinExchange();
	public:
		BitcoinExchange(std::string const &filename);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();
		class CannotOpenFile : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: could not open file.");
				}
		};
};

#endif
