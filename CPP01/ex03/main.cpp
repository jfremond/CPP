/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:23:25 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/25 22:18:21 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	empty;
		HumanA	jack("Jack", empty);
		jack.attack();
		empty.setType("some other type of club");
		jack.attack();
		std::cout << std::endl;
		
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << std::endl;
	}
	{
		Weapon	club;
		HumanB	john("John");
		john.attack();
		club.setType("a magnificent type of club");
		john.attack();
		std::cout << std::endl;
		
		Weapon	empty;
		HumanB	jim("Jim");
		jim.setWeapon(empty);
		jim.attack();
		empty.setType("some other type of club");
		jim.attack();
		std::cout << std::endl;

		Weapon	gun = Weapon("gun");
		HumanB	james("James");
		james.attack();
		james.setWeapon(gun);
		james.attack();
	}
	return 0;
}