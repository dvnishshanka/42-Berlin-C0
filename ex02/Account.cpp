#include <iostream>
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
	std::cout << Account::_displayTimestamp() << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
};

// constructor
Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts ++;
	Account::_totalAmount += initial_deposit;
};

// Destructor
Account::~Account( void ){};

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits ++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits ++;
};

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_amount -= withdrawal;
	this->_nbWithdrawals ++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals ++;
};

// setters
int		Account::checkAmount( void ) const
{
	return (this->_amount);
};

void	Account::displayStatus( void ) const
{
	std::cout << Account::_displayTimestamp() << "index:" << this->_accountIndex << ";amount:" << this->_amount << std::endl;
};

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
	return (std::time(nullptr));
};



	// Account( void );