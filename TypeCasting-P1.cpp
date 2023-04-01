#include <iostream>
using namespace std;

int main()
{
    int a{7},b{3};
    float c;
    //float c = a/b;// here it still loss of data because int/int gives int. so it's 1st rhs is performed and copied to lhs
    //c= float(a/b); //c style cast to be avoided
    c= static_cast<float>(a)/b;
    cout<<c;
    //re inetrpret cast to cast b/w 2 diff types
    // const cast for casting constants
    // c style cast makes loss of qualifiers, allows 2 different casting
    const int d = 78;
    int *p = const_cast<int*>(&d);

}