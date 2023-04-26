#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class PrettyPrinter
{
	T * m_pData;
public:
	PrettyPrinter(T* data) :m_pData{ data }{ }
	 void Print()
	 {
		 cout << *m_pData << endl;// for vector this returns vecotro object itself so we go for special print function
	 }
	 T *GetData() //this and ctor return T ** when char * is passed so we created seperate 
	 {
		 return m_pData;
	 }
};
template<>
void PrettyPrinter<vector<int>>::Print()
{
	cout << "{";
	 for(const auto &x:*m_pData)
	 {
		 cout << x;
	 }
	 cout << "}";
}
//specialized class template is written below to support const char*. T can accept only pass by value types not pointer types.
template<>
class PrettyPrinter<const char*>
{
	const char* m_pData;
public:
	PrettyPrinter(const char* data) :m_pData{ data } { }
	void Print()
	{
		cout << m_pData << endl;
	}
	const char* GetData()
	{
		return m_pData;
	}
};
//vector specialization
//template<>
//class PrettyPrinter<vector<int>>
//{
//	vector<int> *m_pData;
//public:
//	PrettyPrinter(vector<int> *data) :m_pData{ data } { }
//	void Print()
//	{
//		for (const auto& x : *m_pData)
//				 {
//					 cout << x;
//				 }
//	}
//	vector<int> *GetData()
//	{
//		return m_pData;
//	}
//};
int main()
{
	int data = 5;
	PrettyPrinter<int> p1(&data);
	p1.Print();

	const char* a{ "Amutamil" };
	PrettyPrinter<const char*> p3(a);
	p3.Print();
	const char* pData = p3.GetData();

	vector<int> v{ 1,2,3,4 };
	PrettyPrinter<vector<int>> pc(&v);
	pc.Print();
	return 0;
}