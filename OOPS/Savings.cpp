#include "Savings.h"
Savings::Savings(string name, float balance, float rate):Account(name, balance), m_rate{rate}
{
	cout << "Savings ctor" << endl;
}
Savings::~Savings()
{
	cout << "~Savings dtor" << endl;
}
void Savings::AccumulateInterest()
{
	m_Balance += (m_Balance * m_rate);
}
float Savings::GetInterestRate()
{
	return m_rate;
}
