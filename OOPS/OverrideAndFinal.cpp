#include <iostream>
using namespace std;

/**
 * \brief PURE VIRTUAL FUNCTION AND ABSTRACT CLASS
 *	1. pure virtual function has no entry in vtable but create entry for a that function in derived classed
 *	2. The class which contains PVF is abstract class, that function if not overriden by derived classes then they become abstract classes
 *	3. Abstract class can't be instantiated, but used through a pointer or ref.
 *	4 Abstract class used to create interfaces only containing virtual members) which is used to create modules which is used by diff apps
 *	5.Virtual func doen't have implementation(optional)
 *	 6.cannot be invoked(except by derived class if defined)
 *	  7. must be overriden by derived classes
 */
class Document
{
public:
	virtual void serial(float version) = 0;//pure virtual function
	virtual ~Document(){}
};

class Text : public Document
{
public:
	void serial(float version) override final
	{
		cout << "Text::Serial";
	}
};

class RichText : public Text
{
public:
	//won't work as final is added in Text::serial function'
	////void serial(float version) override{cout << "Document::Serial";}
};
class XML:public Document
{
public:
	void serial(float version) override
	{
		cout << "XML::Serial";
	}
};

void Write(Document *p)
{
	p->serial(1.1f);
}
int main()
{
	Text t;
	Document& doc = t;
	doc.serial(1.1f);//!!! having doc::serial int type and text::serialize::float type also and this float is still invoking the doc type
	XML x;
	Write(&x);
	return 0;
}


// override - used to override base class function
// final - used to prevent function from further polymorphed by it's child classes
// !!! seems like override doesn't do anything additional to virtual so is it just for type safe