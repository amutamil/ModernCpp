#include <iostream>
#include "Integer.h"
using namespace std;

class Product
{
	Integer m_Id;
public:
	Product(const Integer& id):m_Id{id}
	{
		cout<<"Product(const Integer&)"<<endl;
		  //m_Id = id; calls rvalue copy constructor
	};
	~Product()
	{
		cout<<"destructor";
	};

};
int main()
{
	//Integer a{6};//init calls only on ctor
	 //a= 5; // assignment calls 3 ctors
	 Product p {1};
}