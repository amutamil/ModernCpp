#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
   Account Amu("Amu", 1000);
   cout << "int bal" << Amu.GetBalance();
   Amu.Withdraw(100);
   Amu.Deposit(1000);
   cout << " bal" << Amu.GetBalance();

}