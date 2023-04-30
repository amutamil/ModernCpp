#include <iostream>
#include "Integer.h"
using namespace std;

void print(Integer a){}

int main()
{
    //ctors do type casting
    
   Integer a{1}; // explicit calling of arg ctor, // this is initialisation so explicit
    Integer b = 8; // implicit calling
    print(4); // implicit calling
    a = 8; // this is assignment so implicit
    int f = static_cast<int>(a);
    cout<<f;
}