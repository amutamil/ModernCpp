#include <iostream>
#include <memory>
#include "Integer.h"
using namespace std;

class Intptr
{
   Integer *m_pInt;
/// <summary>
/// This object is smart pointer,
/// it automatically deletes the memory allocted memory
/// the priciple behind this is RAII idiom = Resourse acquisition Is Initialization -> the lifetime of resource is bound to a local object.
/// </summary>
public:
   Intptr(Integer* i):m_pInt{i}
   {
   };
    ~Intptr()
    {
       delete m_pInt;
    }
    Integer* operator ->() const
    {
       return m_pInt;
    }
    Integer& operator *() const
    {
       return *m_pInt;
    }
    
};

void process(unique_ptr<Integer> p)
{
   (*p).SetValue(6);
   cout << (*p).GetValue();
}
void process(shared_ptr<Integer> p)
{
   /// <summary>
   /// when obj copy is created for shared ptr the reference counting is incremented by 1 by compiler, and decreamented at the deletion of object, so when reference counting = 0, it means all resourses released. in this program RC increases to 2 and get decreamented to 1 in end of this function and decreamented to 0 at end of main function 
   /// </summary>
   /// <param name="p"></param>
   cout << (*p).GetValue();
}

void CreatePtr()
{
	//Intptr i = new Integer;
    std::unique_ptr<Integer> p(new Integer);
    std::shared_ptr<Integer> q(new Integer);
   process(move(p));
    process(q);
    //p->SetValue(6); !!! this throws error as resource is moved
    q->SetValue(10); // this can be done because only copy of obj is created with shared ptr
    //delete i;
}

int main()
{
   CreatePtr();
}