/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:45:17 by argomez           #+#    #+#             */
/*   Updated: 2023/02/24 11:06:54 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "created" << std::endl;
	return ;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
	return ;
}

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount(void){
	return (Account::_totalAmount);
}
int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals(void){
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals()	<< std::endl;
}

void	Account::makeDeposit(int deposit){
	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount - deposit << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

void	Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	if (this->checkAmount() < withdrawal)
	{
		std::cout	<< "index:" << this->_accountIndex << ";"
					<< "p_amount:" << this->_amount << ";"
					<< "withdrawal:refused" << std::endl;
		return (0);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount + withdrawal << ";"
				<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return (0);
}

int		Account::checkAmount(void) const{
	return (this->_amount);
}

void	Account::_displayTimestamp(void){
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [18];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,18,"[%Y%m%d_%H%M%S]",timeinfo);
	std::cout << buffer << " ";
}