#include <iostream>
#include "MyAwesomePhoneBook.hpp"

MyAwesomePhoneBook::MyAwesomePhoneBook(void)
{
	std::cout << "MyAwesomePhoneBook constructor called" << std::endl;
}

MyAwesomePhoneBook::~MyAwesomePhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	main(void)
{
	MyAwesomePhoneBook	test;

	std::cout << "lol" << std::endl;
	
	return (0);
}