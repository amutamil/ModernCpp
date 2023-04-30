#include <iostream>
using namespace std;
const char* combine(const char* a, const char* b) 
{
   //char fullname[20];
   // thsi is fixed size and scope ends when this function returns, so using new char allocation
   char* fullName = new char[strlen(a) + strlen(b) + 1];
   strcpy(fullName, a);
   strcat(fullName, b);
   return fullName;
}

int main()
{
   char first[10];
   char last[10];
   cin.getline(first, 10);
   cin.getline(last, 10);
   const char* fullName = combine(first, last);

   cout << fullName << endl;
   delete[] fullName;
   //delete is used to free memory created in heap using new char. [] is used as is array type.
   //working with c style strings is error prone and complex so we go with c++ strings
}