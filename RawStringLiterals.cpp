#include <iostream>
#include<iostream>
using namespace std;

int main()
{
   string filename{ R"(C:\temp\file.txt)" };//using R in front makes the string raw string literal so that we need not to add additional escape chars
   cout << filename << endl;
    string name{R"MSG(c++ introduces file handling api in "(c++17)")MSG"};//MSG is user defines escape character
    cout << name << endl;

}