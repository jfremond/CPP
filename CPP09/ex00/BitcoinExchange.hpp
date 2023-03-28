/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:17:36 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/28 19:44:57 by jfremond         ###   ########.fr       */
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

#endif
