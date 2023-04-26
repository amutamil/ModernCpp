#include <iostream>
using namespace std;

/**
 * \brief 
 * 1. compiler internally implements function object )overloading call operator inside anonymous class)
 * 2. LE can be passes as function arg for function accepting functor as arg
 * 3. using auto keyword we can assign LE to a variable
 * 4. LE behaves as same as normal function
 * SYNTAX:
 * [](){}
	with optional args:
   [](<args>)<mutable><exception specification>->{<return type>
   }
 */
template<typename T>
struct Unnnamed
{
	T operator()(T a,T b){
      return a + b;
	}
};// internal implementation by compiler for sum.

int main()
{
   auto fn = []() {
      cout << "this is lambda expression" << endl;
   };
   cout << typeid(fn).name() << endl;
    //fn is function object instance now
   fn();//invoking by using function call operator
   auto sum = [](auto x, auto y)noexcept->auto{
      return x + y;
   };//generic lambda function(accepting all data types as argument)
   cout<<sum(1, 2) << endl;
}