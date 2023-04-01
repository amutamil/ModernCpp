#include <iostream>
using namespace std;

class car
{
public:
	int speed{};
private:
	void accelerate();
	 void brake();
};

void Foo(const car & car)
{
	
}
void car::accelerate()
{
	Foo(*this);
}

int main()
{
	car c1;
	 c1.speed= 7;

}