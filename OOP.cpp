/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
/*
1. Classes are user-defined data types that act as the blueprint for individual objects, attributes and methods.

2. Objects are instances of a class created with specifically defined data. Objects can correspond to real-world objects or an abstract entity. When class is defined initially, the description is the only object that is defined.

3. Methods are functions that are defined inside a class that describe the behaviors of an object. Each method contained in class definitions starts with a reference to an instance object. Additionally, the subroutines contained in an object are called instance methods. Programmers use methods for reusability or keeping functionality encapsulated inside one object at a time.

4. Attributes are defined in the class template and represent the 
state of an object. Objects will have data stored in the attributes field. Class attributes belong to the class itself.
*/
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