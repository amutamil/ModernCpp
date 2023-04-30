#include <iostream>
using namespace std;


inline int square(int x) // inline sud be mentioned in defenition
{
	return x * x;
}

int main()
{
	int val =3;
	cout<<square(val);
}

