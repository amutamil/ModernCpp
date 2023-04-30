#pragma once
#include "Account.h"
class Savings :
    public Account
{
private:
   float m_rate;
public:
   Savings(string name, float balance, float rate);
   ~Savings();
   void AccumulateInterest();
   float GetInterestRate();
};

