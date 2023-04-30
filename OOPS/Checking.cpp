#include "Checking.h"

//Checking::Checking(string& name, float amount):Account(name, amount) {}

//Checking::~Checking() {}
Checking::Checking(string name, float balance, float minBalance) :m_MinimumBalance{ minBalance }, Account{ name, balance }{}

void Checking::Withdraw(float amount)
{
	if (m_Balance - amount > m_MinimumBalance)
	{
		Account::Withdraw(amount);
	}
	else
		cout << "invalid amount" << endl;
}
