#include <iostream>
#include "Checking.h"
#include "Savings.h"
#include "Transact.h"
using namespace std;

int main()
{
   //Savings acc("A", 100, 0.05f);//!!! name pass by reference not working
 //  Account* acc = new Savings("A", 100, 0.05f);
	//Transact(acc);
 //  delete acc;

 //  Checking ch("Amu", 100, 50);
 //  Account& ac = ch; // up-casting - casting child obj to base class obj
 //  Account* ac2 = &ch;
 //  
 //  Checking* ch2 = static_cast<Checking*>(ac2);//down casting - it need static cast as other child classes also there
   /// <summary> of Object slicing
   /// 1.Upcasting to be done either by pass by reference or by pointer
   /// 2.If passed by value then compiler slice the extra memory from child object to prevent memory errors. !!! check if how it's implemented
   ///
   /// </summary>
   /// <returns></returns>
   ///
   ///Objectid - return the information of the type as an obejct of the type info class
   Savings acc("Amu", 1000, 30);
    try
    {
       Transact(acc);
    }catch (exception &ex)
    {
       cout << ex.what() << endl;
    }
   
   return 0;

}