#pragma once
#include<iostream>
using namespace std;

class Account
{
private:
   string m_Name;
   int m_AccNum;
   static int ANGen;
protected:
   float m_Balance;
public:
   Account(string name,float amount);
   ~Account();

   const string GetName() const;
   float GetBalance() const;
   int GetAccNo() const;

   void AccumulateInterest();
   void Deposit(float amount);
   void Withdraw(float amount);
   float GetInterestRate();
};

