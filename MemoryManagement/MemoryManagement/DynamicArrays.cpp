#include <iostream>
using namespace std;

int main()
{
    //deleter will call delete not call delete subscript, we need to write user defined deleter for array type to call delete subscript for underlying pointer
   std::unique_ptr<int> p{new int[5]{1,2,3,4}};
    // automatically calls subscript deleter, array access syntax is also easy
   std::unique_ptr<int[]> q {new int[5]{1,2,3,4}};
	p.get()[1] = 8;
    q[1] = 0; // syntax is simple

}