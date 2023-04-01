#include <iostream>
using namespace std;
enum class color: char{RED='a', GREEN, BLUE};
enum class traffic  { RED=8, GREEN, BLUE };
//class key scopes the enum

void fill(color a)
{
	if(a == color::RED)
	{
		cout<<"RED"<<endl;
	}else if (a == color::GREEN)
	{
		cout << "GREEN" << endl;
	}
	else if (a == color::BLUE)
	{
		cout << "BLUE" << endl;
	}
}

int main()
{
	color c = color::RED;
	color d = static_cast<color>(traffic::RED);
	std::cout<<static_cast<int>(d);
}