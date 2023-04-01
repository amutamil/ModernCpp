#include <iostream>
#include "Integer.h"
using namespace std;
Integer operator+(int a, const Integer& b)
{
	return(a + b.GetValue());
}

/**
 * \brief
 *	Hence ">>" operator is overloaded in ostream class we can't overload it again in Integer class, so we overloading as global.
 * \return 
 */
std::ostream & operator <<(std::ostream &cout, Integer &a)
{
	cout << a.GetValue();
	 return cout;
}

void operator >>(std::istream &cin, Integer &a)
{
	 ///in course return type was declared, but it's redundant so removed
	int x;
	 cin >> x;
	 a.SetValue(x);
	
}
int main()
{
	Integer a{},b(4);
	cin >> a;
	Integer sum1 = a+b;
	Integer sum2 = a+5; //type conversion of primitive type to user defined Integer type
	Integer sum3 = 6+a;
	
	cout << sum1 << endl;
	/// <summary>
	/// translation of above line
	/// ***operator<<(std::cout,a).operator<<(std::endl);***
	/// first operator calls the function defined in here,
	/// second operator calls default inside ostream class function
	/// </summary>
	/// <returns></returns>
	cout << sum2.GetValue() << endl;
	cout << sum3.GetValue() << endl;

	 a();
}
