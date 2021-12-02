// friend function of a class can access the private variables of that class . Doesn't have a this pointer . 
// friend funtion also works as a forward declaration

// A friend function can be a global function not related to any particular class.
// It can also be a member of another class.
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


// Forward declaration 
// class Coord;
// Coord operator+(const int& n,const Coord& c);



class A{
public:
	void f(){

	}
};

class Coord{
	int x, y;
	char *pointname;
public:
	friend Coord operator+(const int& n,const Coord& c);	// Global function
	friend void A::f();		// Function of another class
	static void main(){
		Coord ob1,ob2;

		// If we don't declare this function as friend in class Coord, then this statement will be invalid. Error: No match for operator+ (operand types are 'int' and 'Coord')
		ob1 = 100 + ob2;

		// We can overcome this, by forward declaration of the method
	}
};
Coord operator+(const int& n,const Coord& c){
	Coord temp;
	// If we don't declare this function as friend in class Coord, then we won't be able to access private variables x,y
	// We can overcome this, by using setter and getters
	temp.x = c.x + n;	
	temp.y = c.y + n;
	return temp;
}

int main(){Coord::main();}

