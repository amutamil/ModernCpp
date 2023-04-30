#include <iostream>
using namespace std;

/**
 * \brief When Child class instances are created then the ctor of child class wil 
 * create an instance of base class stream, and so the Stream class has parametrized ctor, so we have call that parameterised ctor in IOStream
 */
class Stream
{
   string m_FileName;
public:
   Stream(const string& fileName):m_FileName{fileName}
   {
      cout << "Stream()" << endl;
   }
   string GetFileName()
   {
      return m_FileName;
   }
   ~Stream()
   {
      cout << "~~Stream()" << endl;
   }
};

class OutputStream:virtual public Stream
{
   ostream& out;
public:
   OutputStream(ostream& o,const string& fileName):Stream{ fileName }, out{ o }
   {
      cout << "OutputStream()" << endl;
   }
   ~OutputStream()
   {
      cout << "~~OutputStream()" << endl;
   }
   ostream & operator <<(const string& data)
   {
      out << data;
      return out;
   }
};

class InputStream :virtual public Stream
{
   istream& in;
public:
   InputStream(istream& i,const string& fileName) :Stream{ fileName }, in{ i }
   {
      cout << "InputStream()" << endl;
   }
   ~InputStream()
   {
      cout << "~~InputStream()" << endl;
   }

   istream& operator >> (string& data)
   {
      in >> data;
      return in;
   }
};

class IOStream:public OutputStream, public InputStream
{
public:
	IOStream(const string& fileName):OutputStream(cout,fileName),InputStream(cin,fileName),Stream(fileName)
	{
      cout << "IOStream()" << endl;
	}
   ~IOStream()
	{
      cout << "~~IOStream()" << endl;
	}
};

int main()
{
   IOStream io("file");
   string data;
   cin >> data;
   cout << data;
   cout << io.GetFileName() << endl;
}

