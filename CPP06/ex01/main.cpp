/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:43:24 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/13 20:56:17 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

struct	Data
{
	std::string	str;
	int			value;
};


uintptr_t	serialize(Data *ptr)
{
	uintptr_t	res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data	*deserialize(uintptr_t raw)
{
	Data	*res = reinterpret_cast<Data *>(raw);
	return res;
}

int	main(void)
{
	Data	*src = new Data;
	src->str = "Test";
	src->value = 42;
	uintptr_t	raw;
	Data	*cpy;
	raw = serialize(src);
	cpy = deserialize(raw);
	std::cout << cpy->str << std::endl;
	std::cout << cpy->value << std::endl;
	delete src;
}