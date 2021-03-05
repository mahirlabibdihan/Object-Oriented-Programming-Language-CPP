#include<iostream>
#include<string>
using namespace std;

class Animal{
private:
	int Height,Weight;
protected:
	string Name;
public:
	int Color;
};

class Dog:private Animal{
	// Height and Weight is not inherited .
	// Access Specifier of name is Private .
	// Access Specifier of color is Private .
};

class Cat:protected Animal{
	// Height and Weight is not inherited .
	// Access Specifier of name is Protected .
	// Access Specifier of color is Protected .
};

class Mouse:public Animal{
	// Height and Weight is not inherited .
	// Access Specifier of name is Protected .
	// Access Specifier of color is Public .
};

int main()
{
	
}