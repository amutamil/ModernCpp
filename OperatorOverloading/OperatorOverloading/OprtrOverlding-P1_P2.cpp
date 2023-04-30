#include <iostream>
#include "Integer.h"
using namespace std;
/*Integer operator+(const Integer& a, const Integer& b)
{
	return(a.GetValue() + b.GetValue()); // !!!thid didn't call move ctor. instead calling cpy ctor???
}*/

int main()
{
	Integer a(2);
	//Integer sum = a+b;

	 Integer c=a; //calling cpy ctor not the =(assignment operator)
	cout<<c.GetValue()<<endl;
}