/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:41:33 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/10 04:25:08 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	AMateria* tmp2;
	tmp2 = src->createMateria("ice");
	AMateria* tmp3;
	tmp3 = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp2);
	me->equip(tmp3);
	// me->equip(tmp);
	AMateria *tmp1;
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);

	ICharacter* bob = new Character("Bob");
	me->use(4, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	delete bob;
	// ! Pas de delete les tmp parce que c'est fait dans le destructor de Character
	// ! T'as quand même segfault longtemps à cause de ça
	// delete tmp1;
	// delete tmp;
	delete me;
	delete src;
    return (0);
}