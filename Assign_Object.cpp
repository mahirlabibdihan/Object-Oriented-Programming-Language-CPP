// One object can be assigned to another provided that both objects are of the same type
// By default, when one object is assigned to another, a bitwise copy of all the data members is made, including compound data structures like arrays
// Creates problem when member variables point to dynamically allocated memory and destructors are used to free that memory

// Assignment operator is the only operator which can operate on objects by default . All others operators can't operate objects . We have to overload them to operate on objects .
// For this reason assignment operator must be overloaded as nonstatic member function . Otherwise it will create ambiguity between the overloaded and the default function . 
// Assign operator can't be overloaded as static member function , friend function , free function , functions in namespaces .
class Point{
	float x, y;

	// Valid
	Point& operator=(Point A)
	{
		this->x = A.x;
		this->y = A.y;
		return *this;
	}

	// Invalid
	static Point& operator=(Point& p,Object o)
	{
		this->x = A.x;
		this->y = A.y;
		return *this;
	}

	// Invalid
	friend Point& operator=(Point& p,Object o);
};

// Invalid
Point& operator=(Point& p,Object o)
{

}

int main()
{

}