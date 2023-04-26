#include <iostream>
using namespace std;
template<typename T, int size>
class Stack
{
	T m_Buffer[size];
	int m_Top{ -1 };
public:
	Stack() = default;
	Stack(const Stack& obj):m_Top {
		obj.m_Top}//copy ctor
	 {
		 //m_Top = obj.m_Top;
		  for(int i=0;i<=m_Top;++i)
		  {
			  m_Buffer[i] = obj.m_Buffer[i];
		  }
	 }
	void Push(T val) {
		  if(m_Top<size-1)
			  m_Buffer[++m_Top] = val;
	}
	void Pop();

	 const T& Top() const
	{
		  if(m_Top!=-1)
			  return m_Buffer[m_Top];
		  cout << "Stack is empty" << endl;
		  return -1;
	}

	 bool IsEmpty() const
	{
		 return m_Top == -1;
	}

	 int GetSize() const
	{
		 return m_Top;
	}
	 static Stack Create();// here we used short hand notation(template typenames are not included)
};

// class name  should have argument list as they are part of class name
template <typename T, int size>
Stack<T, size> Stack<T, size>::Create() {
	return Stack<T, size>();
}

template <typename T,int size>
void Stack<T,size>::Pop(){
		if (m_Top >= 0)
			--m_Top;
}

int main()
{
	Stack<int, 3> s = Stack<int, 3>::Create();//size should be in both size
	s.Push(1);
	s.Push(2);
	s.Push(3);
	auto s2(s);
	while(!s2.IsEmpty())
	{
		cout << s2.Top()<<" ";
		s2.Pop();
	}
	return 0;
}