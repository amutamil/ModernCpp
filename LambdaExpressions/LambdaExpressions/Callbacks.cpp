#include <iostream>
using namespace std;

using Comparator = bool (*)(int, int);

template <typename T,int size>
void Sort(T(&arr)[size], Comparator comp)
{
	for (int i=0;i<size-1;++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if(comp(arr[j],arr[j+1]))
			{
				T temp = move(arr[j]);
				arr[j] = move(arr[j + 1]);
				arr[j + 1] = move(temp);
			}
		}
	}
}
// Predicate function = return bool value
//global functions can't have state
//state can't be stores in local var, so global var will be shared by all instantiation
//instead of call backs , function objects also can be used here
//code optimization can't be done on function pointers

bool Comp(int x, int y)
{
	return x > y;
}
bool Comp1(int x, int y)
{
	return x < y;
}

int main()
{
	int arr[]{ 1,3,4,5,2 };
	for (auto x : arr)
		cout << x << " ";
	cout << endl;
	Sort(arr, Comp1);// pass Comp or Comp1 predicate for sort in ascending or descending
	for (auto x : arr)
		cout << x << " ";
	cout << endl;
}