#include <iostream>
#include "../../Integer.h"
using namespace std;

/**
 * \brief
 * 1. Perfect forwarding is used to preserve value type(r-value or l-value) while passing to member templates(templates is member of a class)
 * 2. Template designed with R-value args can accept either r-values or l-values
 * 3. Temporary values are passed as r-values, names vars are considered as l-value so copy ctr will be invoked
 */
class Employee
{
   string m_name;
   Integer m_id;
public:
   /*Employee(const string name, const Integer id) :m_name{name}, m_id{id}//id will call copy ctor of Integer
   {
      cout << "Employee(const string name, const Integer id)" << endl;
   }*/
    template <typename T1, typename T2>
    Employee(T1 && name,T2 &&id):m_name{forward<T1>(name)}, m_id{forward<T2>(id)}// though id is tempo value, as we pass it by name it invokes copy ctor rather than move ctor
    {
       cout << "Employee(T1 && name,T2&& id)" << endl;
    }
};

template <typename T1, typename T2>
Employee *create(T1&& a, T2&& b)
{
   return new Employee(forward<T1>(a), forward<T2>(b));
}
int main()
{
   Employee emp1("Amu", Integer{ 100 });// this can call Integer &&
    //as "name" and "Integer" passed are temporary values, r-value should be passed so we go for templates rather than implementing 4 constructors for 2 values, number of param ctor will keep on increasing as no of params increase
   Integer val{ 100 };
   Employee emp3{ string{"Amu"},val };// this can call copy ctor of 
   auto emp = create("Amu", Integer{ 100 });

}