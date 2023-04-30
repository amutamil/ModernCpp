#include <iostream>
#include "Integer.h"
#include <memory>
using namespace std;
 void display(Integer * p)
 {
	 if(!p)
	 {
		 return;
	 }
	 cout<< p->GetValue()<<endl;

 }

Integer *GetPointer(int value)
{
	Integer *p = new Integer(value);
	 return p;
}

void store(std::unique_ptr<Integer>& p)
 {
	 cout<<"writing ptr in file"<<p->GetValue()<<endl;
 }

void operate(int value)
 {
	//Integer* p = GetPointer(5);
	std::unique_ptr<Integer> p{GetPointer(value)}; // unique ptr has explicit ctor. thats y we can't use assignment over init
 	if (p == nullptr)
	{
		//p = new Integer(value);
		  p.reset(new Integer{value});
	}
	 p->SetValue(100);
	 display(p.get()); // .get() underlying ptr  rather than passing ptr object
	 //delete p;
	 //p = nullptr;
	 p.reset(new Integer(__LINE__));
	 display(p.get());
	 //delete p;
	 //p = nullptr;
	 //store(move(p));
	 move(p); // either move or pass by ref for unique pointer

 }


int main()
{
	 operate(5);
	
}