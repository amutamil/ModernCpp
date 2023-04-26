#include <iostream>
using namespace std;

template<typename T, int column>
class PrettyPrinter
{
	T* m_pData;
public:
	PrettyPrinter(T* data) :m_pData{ data } { }

	void Print()
	{
		cout << "column = " << column << endl;
		cout << *m_pData << endl;
	}

	T* GetData()
	{
		return m_pData;
	}
};
//partial specialization of one template attribute
template<typename T>
class PrettyPrinter<T,80>
{
	T* m_pData;
public:
	PrettyPrinter(T* data) :m_pData{ data } { }

	void Print()
	{
		cout << "Using 80 width" << endl;
		cout << *m_pData << endl;
	}

	T* GetData()
	{
		return m_pData;
	}
};

template<typename T>
class SmartPointer
{
	int* ptr;
public:
	SmartPointer(int* p) :ptr(p) {}

	T* operator ->()
	{
		return ptr;
	}
	 T & operator*()
	{
		 return *ptr;
	}
	  ~SmartPointer()
	{
		  delete ptr;
	}
};

//specializing SmartPointer for array types
//this partial specialization is used in std lib also to support array types for smart pointers
template<typename T>
class SmartPointer<T[]>
{
	int* ptr;
public:
	SmartPointer(int* p) :ptr(p) {}

	T& operator[](int index){
		return ptr[index];
	}
	~SmartPointer()
	{
		delete[] ptr;
	}
};
int main()
{
	int data = 100;
	PrettyPrinter<int, 80>p{ &data };
	p.Print();
	SmartPointer<int> sp{ new int(1) };
	SmartPointer<int[]> spa{ new int[3] };
	spa[0] = 100;
	cout << spa[0];
	
}

//explicit specialization is used when data type is mismatch,
//partial specialization is used when different args need to be used.