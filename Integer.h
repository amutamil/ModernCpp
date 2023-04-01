#pragma once
#include <iostream>
class Integer
{
int *m_pInt;
public:
	Integer();
	 //copy ctor
	 Integer(const Integer &i); // must be call by ref, else this will keep looping
	 // arg ctor
	 Integer(int value);
	 //explicit  Integer (int value); for preventing unnecessary implicit type conversions explicit can be used
	 //mov ctor
	 Integer (Integer && i) noexcept; //!!! noexcept suggested by resharper but donno 
	 int GetValue() const;
	 void SetValue(int value);
	 //oprtr overloadings
	 Integer operator +(const Integer& a) const;
	 Integer& operator ++();
	 Integer operator ++(int) const;
	 Integer& operator =(const Integer &a);
	 Integer& operator =(Integer &&a);
	 ~Integer();

	 void operator()(); // function call operator, can perform any operation on callee object

	explicit operator int(); // type conversion oprtr, no args and no return type
};

