#include <iostream>
using namespace std;

class Printer
{
	weak_ptr<int> m_Value{};
public:
	void SetValue(weak_ptr<int> p)
	{
		m_Value = p;
	}

	void Print() const
	{
		cout << "ref count = " << m_Value.use_count() << endl;
		if (m_Value.expired())
		{
			cout << "resource expired";
			return;
		}
		auto sp = m_Value.lock();
		cout << "sp ref count = " << sp.use_count() << endl;

		cout << "Value is = " << *sp << endl;
	}
};

int main()
{
	Printer prn;
	int num;
	cout << "Enter num = ";
	cin >> num;
	shared_ptr<int> p{new int(num)};
	prn.SetValue(p);
	if (*p > 10)
	{
		p = nullptr;
	}
	prn.Print();
}
