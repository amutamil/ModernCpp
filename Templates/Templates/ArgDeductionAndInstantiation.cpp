#include <iostream>
using namespace std;

template <typename T>
T Max(T a,T b)
{
	return a > b ? a : b;
	cout << typeid(T).name() << endl;
}
//3.explicit instantiation
template char Max(char a, char b);

//4.explicit specialisation
/**
 * Explicit instializaton is used for specific datatypes which the basic template algo can't support or to enhance the algo perfomance
 * Explicit specialisation is already instantiated so it should be in .cpp ather than being in .h file to avoid violation of one definition rule.
 *	Explicit initialisation should be defined after primary template definition
 */
template<>const char * Max<const char*>(const char *a, const char *b)//<const char*> is optional
{
	cout << "strcmp" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

//non type template arguments
// this facilitates us to pass only array as ref and size will be taken care by template
template<typename T , int size>//second is non type template argument which should be constexp
T sum(T (&a)[size])
{
	T sum{};
	for(T x:a)
	{
		sum += x;
	}
	return sum;
}

int main()
{
	std::cout << Max(1, 2) << endl;//1.func template invoked
	 //compiler calculates the template type by argument deduction
	 //we can override arg deduction by explicitely mentioning
	cout << Max<double>(1, 2.3) << endl;
	int (*ptr)(int, int) = Max;//2.taking address of func template)invoked
	std::cout << Max('1', '2') << endl;
	 //explicit specialization
	const char* a = "A";
	const char* b = "B";
	cout << Max(a, b);

	//non-type template argument
	int arr[] = { 1,2,3,4 };
	int(&ref)[4] = arr;// here for creating reference to array we sould explicitly mention the size, which can't have different value than size
	cout << "sum = " << sum(arr) << endl;
}