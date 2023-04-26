#include <iostream>
using namespace std;
void OldCode();
///
///1. function object to be specified at compile time but function pointer isn't
///2. 
///
///

//using Comparator = bool (*)(int, int);

template <typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (comp(arr[j], arr[j + 1]))// now calling function obj = member function
			{
				T temp = move(arr[j]);
				arr[j] = move(arr[j + 1]);
				arr[j + 1] = move(temp);
			}
		}
	}
}

template <typename T, int size, typename Callback>
void ForEach(T (&arr)[size],Callback operation)
{
	for(int i = 0;i<size;++i)
	{
		operation(arr[i]);
	}
	cout << endl;
}

//internal implementation without mutable keyword.
//function call operator is implemented as const function
template<typename T>
struct __Unnamed
{
	T offset;
	 __Unnamed(T off):offset(off){}
	 void operator()(T &x) const
	 {
		 x += offset;
		 ++ offset;
	 }
};

// to pass class member variables to capture list this pointer has to be used
class Product
{
	string name;
	float Price;
public:
	 Product(string n,float p):name{n},Price{p}{}
	 void AssignPrice()
	 {
		 float tax[]{ 12,5,5 };
		 float BP{ Price };
		 auto addTaxes = [BP, this](float tax) {//passing member variable to capture list using this
			 float taxedPrice = BP * tax / 100;
			 Price += taxedPrice;
		 };
		 ForEach(tax, addTaxes);
	 }
	 float getPrice() const
	 {
		 return Price;
	 }
};

int main()
{
	atexit([]() {//can't pass any arg to capture list, the reason is listed in last
		cout << "exitting function...." << endl;
		});
	int arr[]{ 1,3,4,5,2 };
	Product p{ "Amu",500 };
	p.AssignPrice();
	cout << "Price = " << p.getPrice() << endl;
	auto out = [](auto x) {
		cout << x << " ";
	};
	ForEach(arr, out);
	int offset = 5;
	int sum = 0;
	/// <summary>
	/// 1. [&] - captures all local vars by scope by reference
	/// 2. [=] - captures all local vars in scope by value
	/// 3. [&, offset]
	/// 4. [&sum, =] 
	/// </summary>
	/// <returns></returns>
	auto addOffset = [offset](auto& x)mutable {
		//offset is copied value/captured by value
		  //mutable makes the function call operator non constant
		x += offset;
		++offset;
	};
	auto sumOf = [&sum](auto x)mutable {
		sum += x;
	};
	ForEach(arr, sumOf);
	ForEach(arr, out);
	cout << sum << endl;

	 //nested LE
	[](int x) {
		x *= 2;
		[](int x) {
			cout << "x value = " << x << endl;
		}(x);
	}(3);
}

void OldCode()
{
	//Comp(3, 4);
	//Comp2 comp;
	//comp(1, 2);//comp.operator()(1,2);
	//though above is similar to Comp call, it's a member call hence it's state can be stored.
	int arr[]{ 1,3,4,5,2 };
	for (auto x : arr)
		cout << x << " ";
	cout << endl;
	auto ascend = [](auto a, auto b) {
		return a > b;
	};
	auto descend = [](auto a, auto b) {
		return a < b;
	};
	Sort(arr,descend);//LE implemented
		/// <summary>
		/// 1. readability increases
		/// 2. no global section is polluted by creating global functors
		/// </summary>
		/// <returns></returns>
	for (auto x : arr)
		cout << x << " ";
	cout << endl;
}

/*
 *!!! if a lambda expression does not specify a captured clause, then it automatically decomposes to a function pointer. So, what does that mean? It means, you can use Lambda expressions as callbacks in C functions. There's a C function called as atexit(). This is used to register callback which is invoked automatically before the program terminates. We can use a Lambda expression here. The callback does not accept any arguments. So, even though a Lambda expression is internally implemented as an anonymous function object, but in this case it will decompose to a function pointer as long as it's capture list is empty. This works because every Lambda expression that does not have a captured list provides a type conversion operator. This type conversion operator returns a pointer to function. The pointer is to an internal static member function inside the Lambda expression. That static member function internally invokes the overloaded function called, operator of the Lambda expression. So, when you use a Lambda inside an expression that requires a function pointer, the type conversion operator of the Lambda expression automatically converts the Lambda into a function pointer. So, this is how it works. But remember for this to work, the Lambda expression should not have any captured list. If it has a captured list then the type conversion operator is not provided. So we can run this and you'll see it has printed, program is exiting at the end. So, this makes Lambda expressions very flexible. But if we capture anything in the captured list then it will not work. So, you see it gives an error, and you can see the error is due to conversion from a function object to a C style function.
 */