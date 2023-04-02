#include <iostream>
#include"Integer.h"
using namespace std;

union UDT {
   Integer i;
   string s;
   // as Integer UD type has used de ctor, we have to write u-def ctor and dtor for union
   UDT() {}
   ~UDT() {}
};

int main()
{
   //placement new operator = only initialize memory but don't allocate. that is used here because union already allocates memory
   UDT udt;
   new(&udt.s)string("go");
   //udt.i = Integer{};// here this instance is not ccreated so we can't use assignment operator
   // variant = type safe union
   new(&udt.i)Integer{};
   udt.i.~Integer(); // we have to manually call the destructor also
}