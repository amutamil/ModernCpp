#include <iostream>
#include "../../Integer.h"
using namespace std;

//template<typename T>
//void Print(initializer_list<T> list)
//{
//	for(const T x:list)
//	{
//		cout << x << endl;
//	}
//}
// The above print function implemented using initializer can access only one type of data so we go for variadic template implementation

void Print()
{
	cout << endl;
}//base case function to end the recursion
//template parameter pack
template<typename T, typename...Params>//params= list of type names
//function parameter pack
void Print(T&& a,Params&&... args)//to prevent copy when user defined type arguments are passed, r-value reference are used
{
	//cout << sizeof...(args) << endl;
	//cout << sizeof...(Params) << endl;
	// cout << a; !!! values not outputting
	 if(sizeof...(args))
	 {
		 cout << ",";
	 }
	Print(forward<Params>(args)...);
}

int main()
{
	//Print({ 1,2,3,4 });
	Integer val(1);
	Print(1, val, Integer{2});
	return 0;
}

/*
 1. Print(1, 2.5, 3, "4");
 2. Print(2.5, 3, "4");
 3. Print(3, "4");
 4. Print("4");
 5. Print(); // calls base case function
 */
