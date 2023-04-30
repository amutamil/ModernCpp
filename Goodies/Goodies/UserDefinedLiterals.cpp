#include <iostream>
using namespace std;
//syntax : <return type> operator"" _<literal>(<arguments>)
// supported type : long double, unsighned long long, char, const char*
class Dist {
   long double m_km;
public:
   Dist(long double km) :m_km(km) {
   }
   long double getKM()
   {
      return m_km;
   };
   long double setKM(long double val)
   {
      m_km = val;
   }
};
Dist operator"" _mi(long double val)
{
   return { val * 1.6 };
}
int main()
{
   Dist dist{ 32.0_mi };
   cout << dist.getKM();
}
//literal operator functions cannot be member functions