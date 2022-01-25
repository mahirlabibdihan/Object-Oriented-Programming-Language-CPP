/*
 Classes can reuse code from other classes. Relationships and subclasses between objects can be assigned, enabling developers to reuse common logic while still maintaining a unique hierarchy. This property of OOP forces a more thorough data analysis, reduces development time and ensures a higher level of accuracy.


 reusability
 eliminate redundant code
*/

// Multiple inheritence
// Miltilevel inheritence
#include <iostream>
#include <string>
using namespace std;

class Animal
{
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

// When deriving a class, default access specifier is private.
// class Dog: Animal{} is equivalent to class Dog: private Animal{}
class Dog : public Animal
{
private:
	string name;

public:
	Dog(string name, int height, int width) : Animal(height, width)
	{
		this->name = name;
	}
	Dog() : Animal()
	{
		this->name = "";
	}
	~Dog()
	{
		cout << this->name << " ";
	}
};

class Color
{
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

// Multiple Inheritence
class Mouse : public Animal, public Color
{
private:
	string name;

public:
	Mouse() : Animal(), Color()
	{
		this->name = "";
	}
	Mouse(string name, int height, int width) : Animal(height, width)
	{
		this->name = name;
	}

	Mouse(string name, int height, int width, short R, short G, short B) : Animal(height, width), Color(R, G, B)
	{
		this->name = name;
	}
	~Mouse()
	{
		cout << this->name << " ";
	}
};

class base
{
public:
	base(int a)
	{
	}
};

class derived : public base
{
public:
	// When derived class construtor is called , Base class constructor is also called by default
	// derived(int a)
	// {

	// }
	// It means
	// derived(int a):base()		// It will give error if there is no base()
	// {

	// }
	derived(int a) : base(a)
	{
	}
};

template <typename E>
class A
{
protected:
	void f1() {}
};
template <typename E>
class B : public A<E>
{
public:
	void f2()
	{
		// f1(); // Error
		this->f1();
		A<E>::f1();
	}
};
int main()
{
	Dog Tom("Tom", 500, 100);
	Mouse Jerry("Jerry", 100, 30, 100, 20, 30);

	Jerry.PrintColor();
}