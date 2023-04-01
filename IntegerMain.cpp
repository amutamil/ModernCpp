#include <iostream>
#include "Integer.h"
using namespace std;

void print(Integer i){};         // invoke default copy ctor as object is pass by value
 Integer Add( int i, int j)
 {
	 return Integer(i +j); // invoke default copy ctor as returning object by return by value
 }
int main()
{
    Integer i(111);
    Integer i2(i);               // invoke default copy ctor but fail in debug if no used defined copy ctor is there because fo shallow copy
    i.SetValue(186);
    cout<<i.GetValue();

}