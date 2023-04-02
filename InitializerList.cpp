#include <iostream>
#include<initializer_list>
#include<cassert> 
using namespace std;
/// <summary>
/// 1. Init list is used to stor array of objects
/// 2. constructed automatically from braced list of elemets
/// 3. not a contained, but has same behavior. !!! what qualifies as container?
/// </summary>

class Bag {
   int arr[10];
   int m_size{};
public:
   Bag(initializer_list<int> data) {
      assert(data.size() <= 10);
      auto it = data.begin();
      while (it != data.end()) {
         Add(*it);
         ++it;
      }
   }
   
   void Add(int value) {
      assert(m_size < 10);
      arr[m_size++] = value;
   }
   void remove() {
      m_size--;
   }
   int operator [](int index) {
      return arr[index];
   }
   int GetSize() const {
      return m_size;
   }
};
int main()
{
   initializer_list<int> data = { 1,2,3,4,5,6,7,8,9,1};
   Bag b{ data };
   for (int i = 0; i < b.GetSize(); ++i)
   {
      cout << b[i] <<" ";
   }
}