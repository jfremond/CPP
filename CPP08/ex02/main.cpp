/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:56:11 by jfremond          #+#    #+#             */
/*   Updated: 2022/12/14 19:29:48 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		std::cout << CYAN << "\tCREATING A MUTANTSTACK THAT CONTAINS INTEGERS" << RESET << std::endl;
		MutantStack<int>	istack;
		
		std::cout << ORANGE << "CHECKING IF THE MUTANTSTACK IS EMPTY" << RESET << std::endl;
		std::cout << "istack.empty(): " << istack.empty() << std::endl; 
		std::cout << std::endl;
		
		std::cout << ORANGE << "PUSHING INTEGERS INTO THE MUTANTSTACK" << RESET << std::endl;
		std::cout << "istack.push(2)" << std::endl; istack.push(2);
		std::cout << "istack.push(-6)" << std::endl; istack.push(-6);
		std::cout << "istack.push(-10)" << std::endl; istack.push(-10);
		std::cout << "istack.push(-2)" << std::endl; istack.push(-2);
		std::cout << "istack.push(-8)" << std::endl; istack.push(-8);
		std::cout << "istack.push(7)" << std::endl; istack.push(7);
		std::cout << "istack.push(5)" << std::endl; istack.push(5);
		std::cout << "istack.push(-3)" << std::endl; istack.push(-3);
		std::cout << "istack.push(-7)" << std::endl; istack.push(-7);
		std::cout << "istack.push(-1)" << std::endl; istack.push(-1);
		std::cout << std::endl;
		
		std::cout << ORANGE << "CHECKING IF THE MUTANTSTACK IS EMPTY" << RESET << std::endl;
		std::cout << "istack.empty(): " << istack.empty() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "ACCESSING THE TOP ELEMENT OF THE MUTANTSTACK" << RESET << std::endl;
		std::cout << "The top element is : " << istack.top() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "DISPLAYING THE SIZE OF THE MUTANTSTACK" << RESET << std::endl;
		std::cout << "The size of the MutantStack is : " << istack.size() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "REMOVING THE TOP ELEMENT OF THE MUTANTSTACK" << RESET << std::endl;
		std::cout << "istack.pop()" << std::endl; istack.pop();
		std::cout << std::endl;
		
		std::cout << ORANGE << "ACCESSING THE TOP ELEMENT OF THE MUTANTSTACK" << RESET << std::endl;
		std::cout << "The top element is : " << istack.top() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "PRINTING THE CONTENTS OF THE MUTANTSTACK" << RESET << std::endl;
		MutantStack<int>::const_iterator	itb = istack.begin();
		MutantStack<int>::const_iterator	ite = istack.end();
		MutantStack<int>::const_iterator	it;
		for (it = itb; it != ite; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "COPYING THE MUTANTSTACK USING THE ASSIGMENT OPERATOR" << RESET << std::endl;
		MutantStack<int>	istack2 = istack;
		MutantStack<int>::iterator	itb2 = istack2.begin();
		MutantStack<int>::iterator	ite2 = istack2.end();
		MutantStack<int>::iterator	it2;
		for (it2 = itb2; it2 != ite2; it2++)
			std::cout << *it2 << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "COPYING THE MUTANTSTACK USING THE CONSTRUCTION BY COPY" << RESET << std::endl;
		MutantStack<int>	istack3(istack);
		MutantStack<int>::iterator	itb3 = istack3.begin();
		MutantStack<int>::iterator	ite3 = istack3.end();
		MutantStack<int>::iterator	it3;
		for (it3 = itb3; it3 != ite3; it3++)
			std::cout << *it3 << std::endl;
		std::cout << std::endl;
	}
	{	
		std::cout << CYAN << "\tCOMPARISON WITH A LIST" << RESET << std::endl;
		std::list<int>	lst;
		
		std::cout << ORANGE << "CHECKING IF THE LIST IS EMPTY" << RESET << std::endl;
		std::cout << "lst.empty(): " << lst.empty() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "PUSHING INTEGERS INTO THE LIST" << RESET << std::endl;
		std::cout << "lst.push_back(2)" << std::endl; lst.push_back(2);
		std::cout << "lst.push_back(-6)" << std::endl; lst.push_back(-6);
		std::cout << "lst.push_back(-10)" << std::endl; lst.push_back(-10);
		std::cout << "lst.push_back(-2)" << std::endl; lst.push_back(-2);
		std::cout << "lst.push_back(-8)" << std::endl; lst.push_back(-8);
		std::cout << "lst.push_back(7)" << std::endl; lst.push_back(7);
		std::cout << "lst.push_back(5)" << std::endl; lst.push_back(5);
		std::cout << "lst.push_back(-3)" << std::endl; lst.push_back(-3);
		std::cout << "lst.push_back(-7)" << std::endl; lst.push_back(-7);
		std::cout << "lst.push_back(-1)" << std::endl; lst.push_back(-1);
		std::cout << std::endl;
		
		std::cout << ORANGE << "CHECKING IF THE LIST IS EMPTY" << RESET << std::endl;
		std::cout << "lst.empty(): " << lst.empty() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "ACCESSING THE TOP ELEMENT OF THE LIST" << RESET << std::endl;
		std::cout << "The top element is : " << lst.back() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "DISPLAYING THE SIZE OF THE LIST" << RESET << std::endl;
		std::cout << "The size of lst is : " << lst.size() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "REMOVING THE TOP ELEMENT OF THE LIST" << RESET << std::endl;
		std::cout << "lst.pop()" << std::endl; lst.pop_back();
		std::cout << std::endl;
		
		std::cout << ORANGE << "ACCESSING THE TOP ELEMENT OF THE LIST" << RESET << std::endl;
		std::cout << "The top element is : " << lst.back() << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "PRINTING THE CONTENTS OF THE LIST" << RESET << std::endl;
		std::list<int>::const_iterator	litb = lst.begin();
		std::list<int>::const_iterator	lite = lst.end();
		std::list<int>::const_iterator	lit;
		for (lit = litb; lit != lite; lit++)
			std::cout << *lit << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "COPYING THE LIST USING THE ASSIGMENT OPERATOR" << RESET << std::endl;
		std::list<int>	lst2 = lst;
		std::list<int>::iterator	litb2 = lst2.begin();
		std::list<int>::iterator	lite2 = lst2.end();
		std::list<int>::iterator	lit2;
		for (lit2 = litb2; lit2 != lite2; lit2++)
			std::cout << *lit2 << std::endl;
		std::cout << std::endl;
		
		std::cout << ORANGE << "COPYING THE LIST USING THE CONSTRUCTION BY COPY" << RESET << std::endl;
		std::list<int>	lst3(lst);
		std::list<int>::iterator	litb3 = lst3.begin();
		std::list<int>::iterator	lite3 = lst3.end();
		std::list<int>::iterator	lit3;
		for (lit3 = litb3; lit3 != lite3; lit3++)
			std::cout << *lit3 << std::endl;
		std::cout << std::endl;
	}
	return (0);
}