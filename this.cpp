#include <iostream>
using namespace std;
class Animal{
	static int Count;
	int Height,Weight;

public:
	Animal()
	{
		Height=0;
		Weight=0;
	}
	
	Animal(int Height,int Weight)
	{
		// Height -> Parameter's Height
		// this->Height -> Objects's Height <- Animal::Height
		this->Height = Height;	
		this->Weight = Weight;
	}

};

int main()
{
	Animal Tom;
	Animal Jerry(50,100);
}