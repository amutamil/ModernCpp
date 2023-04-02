#include <iostream>
#include <sstream>
using namespace std;

int main()
{
   stringstream ss;
   /*
   * 1. stringstream used for converting primitive types and get stored in buffer.
   * 2. stringstream used for parse and convert primitive types
   * 3. ss used internal buffer toimplements this
   */
   int a;
   string s = "12 23 34";
   ss.str(s);

   while(!ss.fail())
   {
      cout << "first";
      ss >> a;
      cout << a << endl;
      // this ouputs last element twice so changing as followed
   }
   /// <summary>
   /// !!! after 1st parsing second parsing couldn't be done in same ss, so using new ss2. Investigate.
   /// </summary>
   /// <returns></returns>
   stringstream ss2;
   ss2.str(s);
   while (ss2 >> a)
   {
      cout << "second";
      cout << a << endl;
   }


}