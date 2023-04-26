#include <iostream>
using namespace std;

///
///1. function object to be specified at compile time but function pointer isn't
///2. 
///
///

//using Comparator = bool (*)(int, int);

template <typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (comp(arr[j], arr[j + 1]))// now calling function obj = member function
			{
				T temp = move(arr[j]);
				arr[j] = move(arr[j + 1]);
				arr[j + 1] = move(temp);
			}
		}
	}
}


bool Comp(int x, int y)
{
	return x > y;
}
bool Comp1(int x, int y)
{
	return x < y;
}

struct Comp2
{
	bool operator()(int x,int y)
	{
		return x > y;
	}
};
//funtion object is an object of class or structure that contains function call operator overloading
int main()
{
	Comp(3, 4);
	Comp2 comp;
	comp(1, 2);//comp.operator()(1,2);
	//though above is similar to Comp call, it's a member call hence it's state can be stored.
	int arr[]{ 1,3,4,5,2 };
	for (auto x : arr)
		cout << x << " ";
	cout << endl;
	Sort(arr, Comp1);
	for (auto x : arr)
		cout << x << " ";
	cout << endl;
}