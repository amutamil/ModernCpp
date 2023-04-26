#include <iostream>
#include <type_traits>
using namespace std;
//static assert can be used to assert the statements during compile time itself
template <typename T>
T Divide(T a,T b)
{
	static_assert(is_floating_point<T>::value, "not floating point");

	return a / b;
}
template<typename T>
void check(T&&)
{
	cout << "is reference?" << is_reference < T > ::value << endl;
	cout << "After removing ref: " << is_reference<typename remove_reference<T>::type>::value << endl;
	
}
int main()
{
	cout << boolalpha;//convert bool value '0', '1' to false and true

	check(3);
	int a{};
	check(a);

	cout << Divide(5.0f, 2.0f);
}