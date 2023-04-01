#include <iostream>
#include "Integer.h"
using namespace std;

class Product
{
	 Integer m_Id;
public:
	Product(const Integer &id):m_Id{id}{};

	~Product() {};

	 const Integer & GetInteger() const
	 {
		 return m_Id;
	 }

	 //instead of function use tc oprtr
	 operator Integer()
	 {
		 return m_Id;
	 }
};
int main()
{
	Product p{5};
	//Integer id = p.GetInteger();
	 Integer id{5};
	 //id = p;// id = p.operator Integer();

	 //if(id == p.GetInteger()) //!!! obfject comparison not working
	 {
		 cout<<"same equal";
	 }
	 return 0;
}