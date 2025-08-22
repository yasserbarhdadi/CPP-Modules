/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:44:57 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/22 18:36:22 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;
static int index;

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);	
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::_displayTimestamp()
{
	time_t time_s;
	char timestamp[50];
	struct tm * datetime;
	time(&time_s);
	datetime = localtime(&time_s);
	strftime(timestamp, 50, "[%Y%m%d_%H%M%S] ", datetime);
	std::cout << timestamp;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";deposit:" << deposit << ";amount:" << checkAmount() + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << checkAmount() - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = index++;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}
