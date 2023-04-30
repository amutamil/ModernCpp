#include <iostream>

int main()
{
	 char name[50];
	std::cout << "enter your name\n";
	std::cin.getline(name,50);
	 std::cout << "your name is "<< name;
	 return 0;
}