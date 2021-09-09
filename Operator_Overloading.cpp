// You cannot overload
// :: (scope resolution)
// . (member selection)
// .* (member selection through pointer to function)
// ?: (ternary conditional) operators
// sizeof
// Operator that can be overloaded using member function :
// +     -     *     /        %        ^
// &     |     ~     !        ,        =
// =     ++    --	 >>		  <<
// ==    !=    &&    ||		  
// +=    -=    /=    %=       ^=       &=
// |=    *=    =     []       ()
// ->    ->*   new   new []   delete   delete []

// Operator that can't be overloaded using member function :
// inserter , extractor

// Overloading cannot change the original precedence of the operator

// The number of operands on which the operator would be applicable cannot be changed too

// Operator functions cannot have default arguments
// But only new and function call() operator can have default argument
// return-type operator # (arg-list)
// {

// }


// Operator overloading can only be done for class or enumerated type.
// Not for primitive data type
// Invalid
/*int operator+(int a,int b){

}*/
#include <iostream>
using namespace std;

class Object{

};
class Point {
private:
	float x, y;

public:
	Point()
	{
		this->x = 0;
		this->y = 0;
	}
	Point(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	

	Point operator-(Point A)
	{
		Point temp;
		temp.x = x - A.x;
		temp.y = y - A.y;
		return temp;
	}
	

	Point operator+(Point A)
	{
		Point B;
		B.x = this->x + A.x;
		B.y = this->y + A.y;
		return B;
	}

	// Prefix
	Point operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}

	// Postfix
	Point operator++(int unused)
	{
		Point temp = *this;
		this->x++;
		this->y++;
		return temp;
	}

	Point& operator=(Point A)
	{
		this->x = A.x;
		this->y = A.y;
		return *this;
	}

	// float operator[](int i)
	// {
	// 	if (i == 0) return x;
	// 	else if (i == 1) return y;
	// 	else return 0;
	// }
	float& operator[](int i)
	{
		if (i == 0) return x;
		else return y;
	}

	void* operator new(size_t size)
	{

	}

	void* operator new(size_t size,int n=0)	// Can have default argument
	{

	}

	void* operator new[](size_t size)
	{

	}

	void operator delete(void*)
	{

	}

	void operator delete[](void*)
	{
		
	}

	void operator*()
	{

	}

	void operator!()
	{
		
	}

	void operator()(){
		
	}
	// Operator overloading using friend function
	// As a friend function does not have a this pointer –
	// For binary operators, both operands must be passed explicitly
	// For unary operators, the single operand must be passed explicitly

	// We cannot use a friend to overload the assignment operator (=)
	// It can be overloaded only by a non-static member operator function
	// friend Point& operator=(Point& p,Object o);

	friend Point operator++(Point &p);
	// 	Here, in case of “++” we must use reference parameter
	//  Otherwise changes made inside the function will not be visible outside and the original object will remain unchanged

	friend Point operator+(float n, Point p);
	friend istream& operator>>(istream& in, Point p);
	friend ostream& operator<<(ostream& out, Point p);
};

Point operator++(Point &p)
{
	p.x++;
	p.y++;
	return p;
}

Point operator+(float n, Point p)
{
	Point temp;
	temp.x = p.x + n;
	temp.y = p.y + n;
	return temp;
}

istream& operator>>(istream& in, Point p)
{
	in >> p.x >> p.y;
	return in;
}

ostream& operator<<(ostream& out, Point p)
{
	out << p.x << " " << p.y << endl;
	return out;
}

/*class array {
	int a[3];
public:
	array() {
		for (int i = 0; i < 3; i++)
			a[i] = i;
	}
	int& operator[](int i)
	{
		return a[i];
	}		// both lvalue and rvalue

	// int operator[ ](int i) {
	//    return a[i];
	// }		// Only rvalue

	int F()
	{
		return 6;
	}
};*/

int main()
{
	Point A(3, 5), B(4, 5);

	A = A + B;


	/*
	array ob;
	ob[0] = 5; // compiler error
	cout << ob[0];
	*/
}