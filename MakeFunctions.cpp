#include <iostream>
using namespace std;

class Point
{
	Point(int a, int b)
	{
	}
};
int main()
{
	 //modern C++ discourage the manual mem mgmnt
   auto p = make_unique<int>(5);
	 //make unique is variadic function so it can take arbitrary types as well as variable number of arguments
	 auto pC = make_unique<Point>(1,2);

	 //but no direct initialisation for dynamic array possible
	 auto pArr = make_unique<int[]>(5);
	 pArr[1] = 2;

	 //shared ptr
   {
	 //ADV : when we use new for shared ptr creation then it call another new internally for control block creation for tracking resources, but when created using make_shared then it calls only one new and one delete instead two
	   auto p = make_shared<int>(3);
		//DIS-ADV : make_ doesn't support custom deleter.
   }
}