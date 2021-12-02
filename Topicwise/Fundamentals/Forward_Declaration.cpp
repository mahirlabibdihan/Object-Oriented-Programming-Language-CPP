// Forward Declaration of Class : We can only use the pointer-to-that-class type before definition .

// Forward Declaration of Structure : We can only use the pointer-to-that-structure type before definition .

// Forward Declaration of Function : Compiler will look for the definition of that function in all the files in the program .

// Forward Declaration of inline Function : Compiler will look for the definition of that function in the same file .

// Forward Declaration of Variable : Compiler will look for the definition of that variable in all the files in the program .
#include<iostream>
using namespace std;

class Animal;
Animal* createAnimal();

int main()
{
	Animal *a=createAnimal();
}

class Animal
{
public:
	Animal()
	{
		cout<<"Animal Created"<<endl;
	}
};

Animal* createAnimal()
{
	return new Animal;
}
