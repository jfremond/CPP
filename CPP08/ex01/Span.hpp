/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:16:49 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/28 18:30:17 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int>	_vec;
		unsigned int 		_size;
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		Span	&operator=(Span const &rhs);
		~Span();
		void	addNumber(int i);
		int		shortestSpan();
		int		longuestSpan();
		template<typename T>void	fillVec(typename T::iterator begin, typename T::iterator end);
		void	printVec();
		class	VecIsFullException : public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("The vector is full");
			}	
		};
		class	NotEnoughValuesException : public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("There are not enough values to find a span");
			}	
		};
};

template <typename T>
void	Span::fillVec(typename T::iterator begin, typename T::iterator end)
{
	typename T::iterator it;
	for (it = begin; it != end; it++)
	{
		addNumber(*it);
		_size++;
	}
}

#endif
