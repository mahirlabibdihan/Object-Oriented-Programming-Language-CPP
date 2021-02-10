#include <iostream>
#include <string>
using namespace std;
class Color {
private:
	short R, G, B;
protected:
	Color()
	{
		R = G = B = 0;
	}
	Color(short R, short G, short B)
	{
		this->R = R;
		this->G = G;
		this->B = B;
	}
	~Color()
	{
		cout << "Discolored" << endl;
	}

public:
	void PrintColor()
	{
		cout << "R : " << R << " G : " << G << " B : " << B << endl;
	}
};

class Animal {
private:
	int height;
	int weight;

protected:
	Animal()
	{
		this->height = 0;
		this->weight = 0;
	}

	Animal(int height, int width)
	{
		this->height = height;
		this->weight = weight;
	}

	~Animal()
	{
		std::cout << "Killed" << std::endl;
	}
};


class Dog: public Animal {
private:
	string name;
public:
	Dog(string name, int height, int width): Animal(height, width)
	{
		this->name = name;
	}
	Dog(): Animal()
	{
		this->name = "";
	}
	~Dog() 
	{
		cout<<this->name<<" ";
	}
};


// Multiple Inheritence
class Mouse: public Animal , public Color {
private:
	string name;
public:
	Mouse():Animal(),Color()
	{
		this->name = "";
	}
	Mouse(string name, int height, int width):Animal(height, width)
	{
		this->name = name;
	}

	Mouse(string name, int height, int width, short R,short G,short B):Animal(height, width),Color(R,G,B)
	{
		this->name = name;
	}
	~Mouse()
	{
		cout<<this->name<<" ";
	}
};


int main()
{
	Dog Tom("Tom",500,100);
	Mouse Jerry("Jerry",100,30,100,20,30);

	Jerry.PrintColor();
}