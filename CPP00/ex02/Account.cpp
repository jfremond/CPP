/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:39:45 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/01 18:05:09 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
	return ;
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
	Account::_totalAmount += initial_deposit;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
	Account::_nbAccounts--;
	return ;
}
	
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

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
	
void	Account::_displayTimestamp(void)
{
	time_t	timestamp = time(NULL);
	tm		*cur_time = localtime(&timestamp);
	std::cout << "["
		<< std::setfill('0') << (1900 + cur_time->tm_year)
		<< std::setw(2) << cur_time->tm_mon
		<< std::setw(2) << cur_time->tm_mday
		<< "_"
		<< std::setw(2) << cur_time->tm_hour
		<< std::setw(2) << cur_time->tm_min
		<< std::setw(2) << cur_time->tm_sec
		<< "] ";
		return ;
}
	
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts <<";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
	return ;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << (this->_amount + deposit) << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";"
		<< "p_amount:" << this->_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawal:" << this->_nbWithdrawals << std::endl;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}
	return (true);
}
int		Account::checkAmount(void) const
{
	return (this->_amount > 0);
}
