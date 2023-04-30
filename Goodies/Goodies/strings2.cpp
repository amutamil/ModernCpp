#include <iostream>
using namespace std;

int main()
{
   string s = "amutamil";
   printf("%s", s.c_str()); //converting std strings to cstyle string
   const char* c = s.c_str(); // !!! when to use const char and string class
   s.length(); 
   // string.length() is const time complexity but strlen is n for time complexity
}