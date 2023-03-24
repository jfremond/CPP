/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:40:27 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/24 05:44:08 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include <map>

int	main()
{
	std::multiset<int>	a;
	
	a.insert(1);
	a.insert(2);
	a.insert(1);

	std::multiset<int>::const_iterator it;
	for (it = a.begin(); it != a.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::multimap<int, int>	b;
	
	b.insert(std::pair<int, int>(1, 1));
	b.insert(std::pair<int, int>(2, 2));
	b.insert(std::pair<int, int>(1, 1));

	std::multimap<int, int>::const_iterator ite;
	for (ite = b.begin(); ite != b.end(); ite++)
	{
		std::cout << ite->first << std::endl;
	}
}