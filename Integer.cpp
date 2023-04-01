#include "Integer.h"

Integer::Integer()
{
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(const Integer& i)
{
	std::cout << "Integer(const Integer& i)" << std::endl;
	m_pInt = new int(*i.m_pInt);
}

Integer::Integer(int value)
{
	std::cout << "Integer(int value)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(Integer&& obj) noexcept
{
	std::cout << "Integer(&&)" << std::endl;
	this->m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::GetValue() const
{
	return *m_pInt;
}

void Integer::SetValue(int value)
{
	*m_pInt = value;
}

Integer Integer::operator+(const Integer& a) const
{
	std::cout << "op+ :: a = " << *m_pInt << "b =" << *a.m_pInt << std::endl;
	return (*m_pInt + *a.m_pInt); // why should we need temp creatiion as this is so simple
	//return temp;
}

Integer& Integer::operator++()
{
	*m_pInt += 1;
	return *this;
}

Integer Integer::operator ++(int) const
{
	Integer temp(*this);
	*m_pInt += 1; //!!! though this func is made const how it's still changing m_pInt value?
	return temp;
}

Integer& Integer::operator=(const Integer& a)
{
	std::cout << "Integer::operator=(Integer& a)" << std::endl;
	if (this != &a)
	{
		//std::cout << "before delete = "<< m_pInt<<std::endl;
		delete m_pInt;
		//std::cout << "after delete = " << m_pInt << std::endl;
		m_pInt = new int(*a.m_pInt);
	}
	 return *this;
}

Integer& Integer::operator=(Integer&& a)
{
	 std::cout<<"Integer::operator=(Integer&& a)"<< std::endl;
	if (this != &a)
	{
		
		delete m_pInt;
		m_pInt = a.m_pInt;
		a.m_pInt = nullptr;
	}
	return *this;
}


Integer::~Integer()
{
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

void Integer::operator()()
{
	std::cout << *m_pInt;
}

Integer::operator int()
{
	return *m_pInt;
}
