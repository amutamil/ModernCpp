#include <iostream>
using namespace std;

class Project
{
	string m_name;
public:
	 void setName(const string &name)
	 {
		 m_name = name;
	 }
	 void ShowProjectDetails() const
	 {
		 cout<< "[prj name]"<< m_name<<endl;
	 }
};

class employee
{
	 shared_ptr<Project> m_project{};
public:
	 void setProject(const shared_ptr<Project>& p)
	 {
		  // not using constructor method to initialise because employee can move outta project so when emp obj get deleted then destructor can call prj deletion which is shared with other emp objects
		 m_project = p;
	 }
	 const shared_ptr<Project> GetProject() const
	 {
		 return m_project;
	 }
};
void showInfo(const shared_ptr<employee> e)
{
	 cout<<"Employee # : ";
	e->GetProject()->ShowProjectDetails();
}


int main()
{
	shared_ptr<Project> prj{new Project{}};
	 prj->setName("PROJ_I");
	 shared_ptr<employee>e1 {new employee{}};
	 // emplyees also created as shared_ptr else in project can't call or use employee(making array or list of emp)
	 e1->setProject(prj);
	 shared_ptr<employee>e2{new employee{}};
	 e2->setProject(prj);
	 shared_ptr<employee>e3{new employee{}};
	 e3->setProject(prj);

	 e3.reset(); // this is creating a shared pointer(object0 type only, not a normal ptr, because this still can call showInfo
	 employee* e4= new employee{};
	 e4->setProject(prj);

	 showInfo(e1);
	 showInfo(e2);
	 showInfo(e3);
	 //showInfo(e4);// now e4 can't call showPrjDetail (member func of prj class) because this is not shared ptr.
	 /// !!! try casting


	 cout<<"reference count "<<prj.use_count()<<endl;
	 prj->ShowProjectDetails();
}