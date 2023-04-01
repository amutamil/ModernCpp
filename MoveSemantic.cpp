#include <iostream>
#include "Integer.h"
using namespace std;
Integer Add(const Integer &a,const Integer &b)
{
	Integer temp;
	 temp.SetValue(a.GetValue()+b.GetValue());
	 return temp;
}
int main()
{
	Integer a(2),b(4);
	 a.SetValue(Add(a,b).GetValue());

}