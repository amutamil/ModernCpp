#include <iostream>
using namespace std;

int add(int i, int j)
{
	return i + j;
}

int main()
{
	int (*fp)(int,int) = &add;
	cout<<fp(1,2);
}