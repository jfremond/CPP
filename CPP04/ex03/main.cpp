/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:24:20 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/14 06:12:21 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void	cleanFloor(Character *me)
{
	if (me->_floor)
	{
		delete me->_floor;
		me->_floor = NULL;
	}
}

int	main(void)
{
	// {	
	// 	std::cout << ORANGE << "LEARNING TOO MANY MATERIA" << RESET << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice);
	// 	src->learnMateria(new Cure);
	// 	src->learnMateria(new Ice);
	// 	src->learnMateria(new Cure);
	// 	src->learnMateria(new Ice);
	// 	src->learnMateria(new Cure);
	// 	delete src;
	// }
	// std::cout << std::endl;
	// {	
	// 	std::cout << ORANGE << "LEARNING A NULL MATERIA" << RESET << std::endl;
	// 	IMateriaSource	*src = new MateriaSource();
	// 	src->learnMateria(new Ice);
	// 	src->learnMateria(NULL);
	// 	src->learnMateria(new Cure);
	// 	delete src;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << ORANGE << "CREATE THE WRONG KIND OF MATERIA" << RESET << std::endl;
	// 	IMateriaSource	*src = new MateriaSource();
	// 	src->learnMateria(new Ice);
	// 	src->learnMateria(new Cure);
		
	// 	AMateria	*tmp_ice;
	// 	AMateria	*tmp_cure;
	// 	AMateria	*tmp_fire;

	// 	tmp_ice = src->createMateria("ice");
	// 	tmp_cure = src->createMateria("cure");
	// 	tmp_fire = src->createMateria("fire");

	// 	delete tmp_ice;
	// 	delete tmp_cure;
	// 	delete tmp_fire;
	// 	delete src;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << ORANGE << "EQUIP A MATERIA NOT CREATED" << RESET << std::endl;
	// 	IMateriaSource	*src = new MateriaSource();
	// 	src->learnMateria(new Ice);
	// 	src->learnMateria(new Cure);
		
	// 	AMateria	*tmp;
	// 	tmp = NULL;

	// 	ICharacter *me = new Character("me");
	// 	me->equip(tmp);
		
	// 	delete src;
	// 	delete me;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << ORANGE << "EQUIP MATERIA ALREADY EQUIPPED" << RESET << std::endl;
	// 	IMateriaSource	*src = new MateriaSource();
	// 	src->learnMateria(new Ice);
		
	// 	AMateria	*tmp;
	// 	tmp = src->createMateria("ice");

	// 	AMateria	*tmp1;
	// 	tmp1 = src->createMateria("ice");
	// 	ICharacter *me = new Character("me");
	// 	me->equip(tmp);
	// 	me->equip(tmp1);
	// 	me->equip(tmp);
		
	// 	delete src;
	// 	delete me;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << ORANGE << "USE VALUES THAT DON'T EXIST" << RESET << std::endl;
	// 	IMateriaSource	*src = new MateriaSource();
	// 	src->learnMateria(new Ice);
	// 	src->learnMateria(new Cure);
		
	// 	AMateria	*tmp;
	// 	AMateria	*tmp1;
		
	// 	tmp = src->createMateria("ice");
	// 	tmp1 = src->createMateria("cure");

	// 	Character *me = new Character("me");
	// 	me->equip(tmp);
	// 	me->equip(tmp1);
	// 	me->unequip(1);
	// 	cleanFloor(me);
	// 	me->use(-1, *me);
	// 	me->use(2, *me);
	// 	me->use(1, *me);
		
	// 	delete src;
	// 	delete me;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << ORANGE << "PART THAT WORKS" << RESET << std::endl;
	// 	IMateriaSource	*src = new MateriaSource();
	// 	src->learnMateria(new Ice);
	// 	src->learnMateria(new Cure);
		
	// 	AMateria	*tmp;
	// 	AMateria	*tmp1;
		
	// 	tmp = src->createMateria("ice");
	// 	tmp1 = src->createMateria("cure");

	// 	Character	*me = new Character("me");
	// 	Character	*bob = new Character("bob");
	// 	me->equip(tmp);
	// 	me->equip(tmp1);
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
		
	// 	delete src;
	// 	delete me;
	// }
	// Character	bob("bob");
	// Character	me(bob);
	// std::cout << me.getName() << std::endl;
	// std::cout << bob.getName() << std::endl;
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		
		AMateria	*tmp;
		AMateria	*tmp1;
		
		tmp = src->createMateria("ice");
		tmp1 = src->createMateria("cure");

		Character	*me = new Character("me");
		Character	*bob = new Character("bob");
		Character	*me2;
		me->equip(tmp);
		me->equip(tmp1);
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(0);
		cleanFloor(me);
		me2 = me;
		// me2->equip(tmp);
		// me2->equip(tmp1);
		me2->use(0, *bob);
		me2->use(1, *bob);
		delete src;
		delete me;
		delete bob;
		// delete me2;
}