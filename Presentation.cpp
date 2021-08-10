// Sometimes operators need return type for chain of operations
// Ex : = += -= ^= |= &= *= /= %= <<= >>=

// Some operators can only be overloaded as member function
// Ex : = [] () ->

#include <iostream>
using namespace std;
class Point
{

public:
	float x, y;

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

	Point operator+(const Point& A)
	{
		Point B;
		B.x = this->x + A.x;
		B.y = this->y + A.y;
		return B;
	}

	Point& operator=(const Point& A)
	{
		this->x = A.x;
		this->y = A.y;
		cout<<"Assigned"<<endl;
		return *this;
	}
	// Prefix vs Postfix operator
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
	// Operator can't be overloaded using member function if the object is at right of the operator (exception: prefix operatos like ++ , -- , * , & , ! ,unary + -)
	Point operator-()
	{
		Point temp;
		temp.x = -x;
		temp.y = -y;
		return temp;
	}

	Point operator+()
	{
		Point temp;
		temp.x = +x;
		temp.y = +y;
		return temp;
	}	

	Point operator[](int a)
	{
		
	}

	Point operator()(int a,int b)
	{

	}
	// Function call operator can take arbitrary number of operands
	
	Point* operator->()
	{
		return this;
	}
	//  it should return something that either is a pointer
	// The -> operator automatically dereferences its return value before calling its argument using the built-in pointer dereference,

	// Operator is overloaded with friend function if the object is at right of the operator (exception post ++ , unary + -) and we need to access the private variables of the class
};

int main()
{
	Point A(1, 2), B(3, 4);
	A=B=A;

	A->x;
}
