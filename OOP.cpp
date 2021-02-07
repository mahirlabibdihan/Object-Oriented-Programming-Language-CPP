#include <iostream>
#include <string>
class Animal {
private:
	std::string name;
	double height;
	double weight;

protected:

public:
	void SetAll(std::string name, double height, double width)
	{
		this->name = name;
		this->height = height;
		this->weight = weight;
	}
	Animal(std::string name, double height, double width)
	{
		this->name = name;
		this->height = height;
		this->weight = weight;
		std::cout << "Welcome " << this->name << std::endl;
	}
	Animal()
	{
		std::cout << "Welcome" << std::endl;
	}

	~Animal()
	{
		std::cout << "Bye" << std::endl;
	}
};


class Dog: public Animal {
public:
	Dog(std::string name, double height, double width): Animal(name, height, width) {};
	Dog(){};
};


int main()
{
	Animal dihan("Dihan", 510, 57);
	Animal momo;
	Dog Takla("Takla", 600, 55);
}