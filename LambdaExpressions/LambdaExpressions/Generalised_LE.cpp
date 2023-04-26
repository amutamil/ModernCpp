#include <iostream>
#include<fstream>
using namespace std;
//using another var name for expression is generalized LE. introduced in c++14
int main()
{
   int x{ 5 };
   auto f = [y = x](int arg) {
      return y + arg;
   };
   cout << f(2) << endl;

   ofstream out{"file.txt" };
   auto write = [out = move(out)](int x)mutable{
      out << x;
   };
   write(1);
}