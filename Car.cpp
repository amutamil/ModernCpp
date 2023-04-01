#include "Car.h"

int Car::m_totalCount = 0;		 // static member variable

Car::Car():Car(0)	//delegating constructors
{
	std::cout << "Car() constructor" << std::endl;
}

Car::Car(float amount):Car(amount,0)
{
	std::cout << "Car(amount) constructor" << std::endl;
}

Car::Car(float amount, int pass)
{
	std::cout << "Car(amount,pass) constructor" << std::endl;
	++m_totalCount;
	 fuel = amount;
	 speed = 0;
	 passengers = pass;
}

Car::~Car()
{
	std::cout << "Car() destructor" << std::endl;
	 Dashboard();			// value's remain stored in member variables of object evn after destructor call. so what destructor doing
}

void Car::totalCount()
{
	std::cout << "Total cars = " << m_totalCount << std::endl;
}

void Car::FillFuel(float amount)
 {
	 fuel = amount;
 }

 void Car::Accelerate()
 {
	 this->speed++;
	 this->fuel -= 0.5f;
 }
 void Car::Brake()
 {
	 speed =0;
 }
 void Car::AddPassengers(int count)
 {
	 passengers = count;
 }
 void Car::Dashboard()
 {
	 std::cout << "Fuel = " << fuel << std::endl;
	 std::cout << "Speed = " << speed << std::endl;
	 std::cout << "Passengers = " << passengers << std::endl;
 }