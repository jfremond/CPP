/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:39:45 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/30 00:42:33 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include <iostream>
#include "Account.hpp"

// Date ([yrmod_hrminsec]) (at every line)
// index:val index;amount:val amount;created
// accounts:val accounts:total:val total;deposits:val deposits:withdrawals:val withdrawals
// index:val index;amount:val amount;deposits:val deposits;withdrawals:val withdrawals
// index:val index;p_amount:val p_amountdeposit:val deposit;nb_deposits:val nb_deposits

// Valeurs "globales"
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;	
};

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	this->_nbAccounts--;
	return ;
};

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	// Make the deposit
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{	
		std::cout << "withdrawal:" << withdrawal << ";";
		// Make the withdrawal
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << "amount:" << this->_amount << ";";
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount > 0);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	// gets current time in seconds
	time_t now = time(0);
	// converts current time in calendar time (year, month, day...)
	tm cal = *localtime(&now);
	std::cout << "[" 
		<< std::setfill('0') << (1900 + cal.tm_year)
		<< std::setw(2) << cal.tm_mon
		<< std::setw(2) << cal.tm_mday
		<< "_"
		<< std::setw(2) << cal.tm_hour
		<< std::setw(2) << cal.tm_min
		<< std::setw(2) << cal.tm_sec
		<< "] ";
}