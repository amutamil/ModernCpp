#include <iostream>
#include <array>
using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	//std::array<int,int> arr throwing error while iterating
	for (const auto &x : arr)//!!!if I add const then whats the use of &(ref) as it's used to alter array elements only
	{
		cout << x << " ";
	}

	/// <summary>
	/// implemetation of range based for loop internally
	/// </summary>
	/// <returns></returns>
	auto&& range = arr; //&&facilitates to iterate l and r value
	 auto begin = std::begin(arr);//arr[0]
	 auto end =std::end(arr);//arr[5]
	 /*
	  * begin and end sud be same type to compare(char array have diff types so can't compare. C++ 17 supports this)
	  * containers sud have begin , end, and comparison, increment operators for iterators
	  */
	 for(;begin!=end;begin++)
	 {
		 cout<<*begin<<" ";
	 }
}
