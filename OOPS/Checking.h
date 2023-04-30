#pragma once
#include "Account.h"

class Checking :
    public Account
{
   float m_MinimumBalance;
public:
   //Checking(string& name, float amount);
   /**
* \brief instead of manually defining constructor we can inherit base class ctor using a 'using' keyword. C++11 was supporting ctor, dtor, assignment operator inheritance drom parent to child class
*/
   //using  Account::Account;
   //~Checking();
   Checking(std::string name, float balance, float minBalance);
   void Withdraw (float amount) final;
    float GetMinimumBalance()
    {
       return m_MinimumBalance;
    }
};

