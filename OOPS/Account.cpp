#include "Account.h"

int Account::ANGen = 1000;
Account::Account(string name, float amount):m_Name{name},m_Balance{amount}
{
	m_AccNum = ++ANGen;
	cout << "Account ctor" << endl;
}

Account::~Account()
{
	cout << "~Account dtor" << endl;
}

const string Account::GetName() const
{
	return m_Name;
}
float Account::GetBalance() const
{
	return m_Balance;
}

int Account::GetAccNo() const
{
	return m_AccNum;
}
void Account::AccumulateInterest() {}

void Account::Deposit(float amount)
{
	m_Balance += amount;
}

void Account::Withdraw(float amount)
{
	if(amount < m_Balance)
	{
		m_Balance -= amount;
	}
	else
	{
		  //!!! while calling from checking amount with insufficient balance this else is not executing, only invalid amount displaying
		cout << "Insufficient balance" << endl;
	}
}

float Account::GetInterestRate()
{
	return 0.0f;
}
