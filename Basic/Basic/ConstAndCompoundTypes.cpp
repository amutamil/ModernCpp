#include <iostream>
using namespace std;

int main()
{
	const int a =10;
	const int *ptr =&a;
	//const int * const ptr =&a;  //to make address also constant so that ptr can't point to some other address
	cout<<"addr of a ="<<ptr << endl;

	const int b = 20;
	ptr = &b;
	cout << "addr of b =" << ptr <<endl;
	//*ptr = 20; can't modify constant using ptr type

}

