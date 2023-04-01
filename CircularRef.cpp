#include <iostream>
using namespace std;

class Employee;

class Project
{
public:
	shared_ptr<Employee> emp{};
	 Project()
	 {
		 cout<<"Project()"<<endl;
	 }
	 ~Project()
	 {
		 cout << "~Project()" << endl;
	 }
};

class Employee
{
public:
	weak_ptr<Project> prj{};
	Employee()
	{
		cout << "Employee()" << endl;
	}
	~Employee()
	{
		cout << "~Employee()" << endl;
	}
};

int main()
{
	shared_ptr<Employee> e{new Employee};
	shared_ptr<Project> p{new Project};

	 e->prj =  p;
	 p->emp = e;

	 //delete e;
	 //delete p;
}