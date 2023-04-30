#include <iostream>
#include <vector>
using namespace std;

// all concreate memory created in runtime by ctor is destroyed but heap memory are not released as if ctor throws and error so the destructor will not be called. so we use RAAI to resolve this
//destructor can't throw exception, if it's throwing then it should be handled within
class A
{public:
	A() { cout << "A()" << endl; };
	~A() { cout << "~A()" << endl; };
};
class B
{
public:
	B() { cout << "B()" << endl; };
	~B() { cout << "~B()" << endl; };
};
class test
{
	unique_ptr<A> a;
	B b{};
	unique_ptr<int> ptr;//int* ptr{};
	string pStr;// char* pStr{};
	vector<int> pArr;// int* pArr{};
public:
	test()
	{
		cout << "test()" << endl;
		a.reset(new A);
		throw runtime_error("failed mem allocation");
		/*a = new A();
		ptr = new int;
		pStr = new char[1000];
		pArr = new int[10000];*/
	};
	 
	~test()
	{
		cout << "~test()" << endl;
		/*delete a;
		delete ptr;
		delete[] pStr;
		delete[] pArr;*/
	};
};
int main()
{
	try {
		test t{};
	}
	 catch(runtime_error &ex)
	 {
		 cout << ex.what() << endl;
	 }
	 return 0;
}