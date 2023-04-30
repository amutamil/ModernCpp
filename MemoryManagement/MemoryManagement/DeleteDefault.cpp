#include <iostream>
using namespace std;


class Integer
{
	int m_pInt;
public:
	 Integer() = default; // not running after default initialization
	Integer(int value)
	{
		m_pInt = value;
	}
	 void setValue( int value)
	 {
		 m_pInt = value;
		  cout<<this->m_pInt;
	 }
	 void setValue(float value) = delete;
};

int main()
{
	Integer i;
	 i.setValue(7);
	 //i.setValue(7.6);// will throw error because of delete used
}