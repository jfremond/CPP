/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:30:14 by jfremond          #+#    #+#             */
/*   Updated: 2022/12/14 22:48:55 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <iostream>
#include <stack>
#include <list>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(MutantStack<T> const &src) : std::stack<T>(src) {};
		MutantStack<T>	&operator=(MutantStack<T> const &rhs)
		{
			this->c = rhs.c;
			return (*this);
		}
		virtual ~MutantStack() {};
		typedef typename std::stack<T>::container_type::iterator		iterator;
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }
};

#endif