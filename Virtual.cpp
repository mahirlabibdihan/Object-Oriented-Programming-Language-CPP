#include <iostream>
#include <string>
using namespace std;
// Pointer of parent class can point to child class .
// Pointer of child class can't point to parent class .

// Constructors cannot be virtual, but destructors can be virtual
 
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
public:
	virtual void Details()
	{no
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
	void Details()
	{
		cout<<"Name : "<<name<<"  ";
		Animal::Details();
	}
};


class Base{
public:
	int i;
};

class D1:virtual public Base{

};

class D2:virtual public Base{

};

class D3:public D1,public D2{
	// contains only one copy of 'i'
};

int main()
{
	Dog Tom("Tom",10,20);

	Animal* A=NULL;	

	A=&Tom;		

	Tom.Details();

	A->Details();

	D3 Obj;

	Obj.i=10;
	Obj.D1::i=100;
	Obj.D2::i=1000;
}