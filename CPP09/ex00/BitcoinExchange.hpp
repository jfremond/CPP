/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:17:36 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/03 12:52:30 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();
		void											parseFile(std::string const &filename);
		class CannotOpenFile : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: cannot open file");
				}
		};
};

#endif
