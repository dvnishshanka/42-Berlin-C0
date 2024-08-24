/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:10:12 by dnishsha          #+#    #+#             */
/*   Updated: 2024/08/24 13:10:14 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

// getters

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
};

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
};

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
};

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
};

// constructor
Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts ++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
};

// Destructor
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:" <<  this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
};

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposits:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:1" << std::endl;
	this->_amount += deposit;
	this->_nbDeposits ++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits ++;
};

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount >= withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:1" << std::endl;
		this->_amount -= withdrawal;
		this->_nbWithdrawals ++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals ++;
		return (true);
	}
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
	return (false);
};

// setters
int		Account::checkAmount( void ) const
{
	return (this->_amount);
};

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
};

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
	time_t now = std::time(0);	// Number of sec since January 1,1970 
	tm * ltm = localtime(&now);

	// The C standard library's tm_year field was designed to store the number of years since 1900.
	// When you retrieve the tm_year from the tm structure, it gives you this offset value, which you must add to 1900 to get the actual year.
	std::cout << "[" << 1900 + ltm->tm_year
	<< std::setfill('0') << std::setw(2) << ltm->tm_mon + 1
	<< std::setfill('0') << std::setw(2)<< ltm->tm_mday << "_" 
	<< std::setfill('0') << std::setw(2) << ltm->tm_hour
	<< std::setfill('0') << std::setw(2) << ltm->tm_min
	<< std::setfill('0') << std::setw(2) << ltm->tm_sec << "]";
};

