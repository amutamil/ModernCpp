#include "Transact.h"
#include <iostream>
#include "Checking.h"
/**
 * \brief
 *	1. To avoid unexpected up-casting we go for using typeid offered by RTTI.
 *  2. For non polymormhic types typeid works on compile time, but in polymorphic types it works on run time
 *	 3. Whatever it is, it will create additional data member in obj class container so it decreases the perfomance, dynamic cast can be used instead of typeid but it's much slower than this
 * \param pAccount 
 */
void Transact(Account* pAccount)
{
	std::cout << "Transaction started" << endl;
	std::cout << "Initial balance" << pAccount->GetBalance() << endl;
	pAccount->Deposit(100);
	pAccount->Withdraw(170);
	 if(typeid(*pAccount) == typeid(Checking))
	 {
		 Checking* pCheck = static_cast<Checking*>(pAccount);
		 cout << "minimum balance" << pCheck->GetMinimumBalance();
	 }
	 //instead of above we can do dynamic casting
	 Checking* pCheck2 = dynamic_cast<Checking*>(pAccount);
	 if(pCheck2!= nullptr)
	 {
		 cout << "minimum balance" << pCheck2->GetMinimumBalance();
	 }
	std::cout << "Interest rate" << pAccount->GetInterestRate() << endl;
	std::cout << "Final Balance" << pAccount->GetBalance() << endl;
};

void Transact(Account& pAccount)
{
	std::cout << "Transaction started" << endl;
	std::cout << "Initial balance" << pAccount.GetBalance() << endl;
	pAccount.Deposit(100);
	pAccount.Withdraw(170);
	if (typeid(pAccount) == typeid(Checking))
	{
		Checking &pCheck = static_cast<Checking&>(pAccount);
		cout << "minimum balance" << pCheck.GetMinimumBalance() << endl;
	}
	//instead of above we can do dynamic casting
	Checking& pCheck2 = dynamic_cast<Checking&>(pAccount);
	cout << "minimum balance" << pCheck2.GetMinimumBalance() << endl;
	std::cout << "Interest rate" << pAccount.GetInterestRate() << endl;
	std::cout << "Final Balance" << pAccount.GetBalance() << endl;
};