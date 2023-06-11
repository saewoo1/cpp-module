#include "Account.hpp"
#include <time.h>
#include <iostream>

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}
int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
    time_t ts;
    char    buf[16];

    time(&ts);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&ts));
    std::cout << "[" << buf << "]";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbDeposits;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposit:" << getNbDeposits() << ";withdrawls:" << getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposit:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawl)
{
    bool    res;
    
    _amount -= withdrawl;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawl;
    if (!checkAmount())
    {
        res = false;
        _amount += withdrawl;
        std::cout << ";withdrawl:refused" << std::endl;
    }
    else
    {
        res = true;
        _totalAmount -= withdrawl;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";withdrawls:" << withdrawl << ";amount:" << _amount << ";nb_withdrawl:" << _nbWithdrawals << std::endl;
    }
    return (res);
}

int Account::checkAmount(void) const
{
    if (_amount < 0)
        return (0);
    return (1);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount" << _amount << ";deposits:" << _nbDeposits << ";withdrawls:" << _nbWithdrawals << std::endl;
}