#include <iostream>
#include <vector>
using namespace std;
/*
 * 1.type alias is preferred over type def
 * 2.type alias facilitate templatising the type alias
 */

//typedef const char* (*PFN)(int); // typedef
using PFN = const char* (*)(int); //type alias
void Show(PFN pfn){}


typedef vector<std::initializer_list<string>> Names;

template <typename T>
vector<std::initializer_list<T>> NamesAlias;// templatized alias


int main()
{

}