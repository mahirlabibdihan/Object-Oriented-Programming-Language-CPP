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
	virtual void Details()
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

	void Details()
	{
		cout<<"Name : "<<name<<"  ";
		Animal::Details();
	}
};

int main()
{
	Dog Tom("Tom",10,20);

	Animal* A=NULL;	

	A=&Tom;		

	Tom.Details();

	A->Details();
}