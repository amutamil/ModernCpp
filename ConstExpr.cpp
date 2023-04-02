#include <iostream>
using namespace std;
constexpr int GetNum()
{
   return 42;
}
constexpr int Add(int a, int b)
{
   return a + b;
}
constexpr int Max(int a, int b)
{
   if (a > b)
      return a;
   return b;// returning more that one statement feauture in constexpr is added in c++14 not though constexpr is feature of c++11
}

int main()
{
   //behave as constexpr func
   constexpr int i = GetNum();
   int arr[i];

   //behave as constexpr func
   const int j = GetNum();
   int arr[j];

   //behave as normal func
   int x = GetNum();

   //behave as constexpr func
   constexpr int sum = Add(GetNum(), 6);

   //behave as normal func
   int a = 9;
   int sum2 = Add(a, 6);
}
/*
* 1. Should accept and return literal types only
* (void, scalar types(int, float, chat), references etc...
* 
* 2. constexpr funstions are  implicitely inline
*/