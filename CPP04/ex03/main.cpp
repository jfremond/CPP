/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:24:20 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/15 23:46:41 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	{	
		std::cout << ORANGE << "LEARNING TOO MANY MATERIA" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		delete src;
	}
	std::cout << std::endl;
	{	
		std::cout << ORANGE << "LEARNING A NULL MATERIA" << RESET << std::endl;
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(NULL);
		src->learnMateria(new Cure);
		delete src;
	}
	std::cout << std::endl;
	{
		std::cout << ORANGE << "CREATE THE WRONG KIND OF MATERIA" << RESET << std::endl;
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		
		AMateria	*tmp_ice;
		AMateria	*tmp_cure;
		AMateria	*tmp_fire;
		tmp_ice = src->createMateria("ice");
		tmp_cure = src->createMateria("cure");
		tmp_fire = src->createMateria("fire");

		delete tmp_ice;
		delete tmp_cure;
		delete tmp_fire;
		delete src;
	}
	std::cout << std::endl;
	{
		std::cout << ORANGE << "EQUIP A MATERIA NOT CREATED" << RESET << std::endl;
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		
		AMateria	*tmp;
		tmp = NULL;

		ICharacter *me = new Character("me");
		me->equip(tmp);
		
		delete src;
		delete me;
	}
	std::cout << std::endl;
	{
		std::cout << ORANGE << "EQUIP MATERIA ALREADY EQUIPPED" << RESET << std::endl;
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice);
		
		AMateria	*tmp;
		tmp = src->createMateria("ice");

		AMateria	*tmp1;
		tmp1 = src->createMateria("ice");
		ICharacter *me = new Character("me");
		me->equip(tmp);
		me->equip(tmp1);
		me->equip(tmp);
		
		delete src;
		delete me;
	}
	std::cout << std::endl;
	{
		std::cout << ORANGE << "USE VALUES THAT DON'T EXIST" << RESET << std::endl;
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		
		AMateria	*tmp;
		AMateria	*tmp1;
		
		tmp = src->createMateria("ice");
		tmp1 = src->createMateria("cure");

		Character	*me = new Character("me");
		Character	*bob = new Character("bob");
		me->equip(tmp);
		me->equip(tmp1);
		me->unequip(1);
		me->cleanFloor();
		me->use(-1, *bob);
		me->use(2, *bob);
		me->use(1, *bob);
		
		delete src;
		delete me;
		delete bob;
	}
	std::cout << std::endl;
	{
		std::cout << ORANGE << "PART THAT WORKS" << RESET << std::endl;
		IMateriaSource	*src = new MateriaSource();		
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		
		AMateria	*tmp;
		AMateria	*tmp1;
		tmp = src->createMateria("ice");
		tmp1 = src->createMateria("cure");

		Character	*me = new Character("me");
		Character	*bob = new Character("bob");
		me->equip(tmp);
		me->equip(tmp1);
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete src;
		delete me;
		delete bob;
	}
	std::cout << std::endl;
	{
		std::cout << ORANGE << "TESTING DEEP COPIES (copy constructor)" << RESET << std::endl;
		MateriaSource	src_materia;
		src_materia.learnMateria(new Ice);
		src_materia.learnMateria(new Cure);
		MateriaSource	cpy_materia(src_materia);

		AMateria	*ice;
		AMateria	*cure;
		ice = src_materia.createMateria("ice");
		cure = src_materia.createMateria("cure");
		
		
		AMateria	*tmp_ice;
		AMateria	*tmp_cure;
		tmp_ice = cpy_materia.createMateria("ice");
		tmp_cure = cpy_materia.createMateria("cure");
		
		Character	lapras("Lapras");
		Character	bob("bob");
		lapras.equip(ice);
		lapras.equip(cure);
		lapras.equip(tmp_ice);
		lapras.equip(tmp_cure);
		
		lapras.use(0, bob);
		lapras.use(1, bob);
		lapras.use(2, bob);
		lapras.use(3, bob);
		
		Character	cpy(lapras);
		lapras.unequip(2);
		lapras.cleanFloor();
		lapras.unequip(3);
		lapras.cleanFloor();
		lapras.use(0, bob);
		lapras.use(1, bob);
		lapras.use(2, bob);
		lapras.use(3, bob);
		cpy.use(0, bob);
		cpy.use(1, bob);
		cpy.use(2, bob);
		cpy.use(3, bob);
	}
	std::cout << std::endl;
	{
		std::cout << ORANGE << "TESTING DEEP COPIES (assignment operator overload)" << RESET << std::endl;
		MateriaSource	src_materia;
		MateriaSource	cpy_materia;
		src_materia.learnMateria(new Ice);
		src_materia.learnMateria(new Cure);
		cpy_materia = src_materia;
		
		AMateria	*ice;
		AMateria	*cure;
		ice = src_materia.createMateria("ice");
		cure = src_materia.createMateria("cure");
		
		
		AMateria	*tmp_ice;
		AMateria	*tmp_cure;
		tmp_ice = cpy_materia.createMateria("ice");
		tmp_cure = cpy_materia.createMateria("cure");
		
		Character	lapras("Lapras");
		Character	cpy;
		Character	bob("bob");
		lapras.equip(ice);
		lapras.equip(cure);
		lapras.equip(tmp_ice);
		lapras.equip(tmp_cure);
		
		lapras.use(0, bob);
		lapras.use(1, bob);
		lapras.use(2, bob);
		lapras.use(3, bob);

		cpy = lapras;		
		lapras.unequip(2);
		lapras.cleanFloor();
		lapras.unequip(3);
		lapras.cleanFloor();
		lapras.use(0, bob);
		lapras.use(1, bob);
		lapras.use(2, bob);
		lapras.use(3, bob);
		cpy.use(0, bob);
		cpy.use(1, bob);
		cpy.use(2, bob);
		cpy.use(3, bob);
	}
}