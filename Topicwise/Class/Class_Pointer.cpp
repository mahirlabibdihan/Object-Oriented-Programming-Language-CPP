#include <iostream>
#include <string>
using namespace std;
// Pointer of parent class can point to child class .
// Pointer of child class can't point to parent class .
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
public:
	void Details()
	{
		cout<<"Height : "<<height<<"  Weight : "<<weight<<endl;
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

	void MakeSound()
	{
		cout<<"Vau Vau"<<endl;
	}
	void Details()
	{
		cout<<"Name : "<<name<<"  ";
		Animal::Details();
	}
};

class Mouse:private Animal{

};


int main()
{
	Dog Tom("Tom",10,20);
	Mouse Jerry;

	Animal* A=NULL;	
	Dog* D=NULL;


	A=&Tom;		
	// A=&Jerry; // Base class can point to derived class only if it is inherited public.

	// D=A;		// Derived class can't point to base class
	D=&Tom;

	cout<<&Tom<<" "<<A<<endl;

	Tom.MakeSound();

	// A->MakeSound();		// Make sound is a member of derived class , not the base class .

	Tom.Details();

	A->Details();
}