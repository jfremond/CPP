/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:39:45 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/29 17:33:29 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	return ;	
};

Account::Account(int initial_deposit)
{
	initial_deposit = 0;
	this->_nbDeposits = initial_deposit;
}

Account::~Account(void)
{
	return ;
};

int	Account::getNbAccounts(void)
{
	return (0);
}

int	Account::getTotalAmount(void)
{
	return (0);
}

int	Account::getNbDeposits(void)
{
	return (0);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "pouet" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	(void)deposit;
	this->_nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	(void)withdrawal;
	this->_totalNbWithdrawals++;
	return (0);
}

int	Account::checkAmount(void) const
{
	return (0);
}

void	Account::displayStatus(void) const
{
	std::cout << "prout" << std::endl;
}