/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/

// One object can be assigned to another provided that both objects are of the same type
// By default, when one object is assigned to another, a bitwise copy of all the data members is made, including compound data structures like arrays
// Creates problem when member variables point to dynamically allocated memory and destructors are used to free that memory

// Assignment operator is the only operator which can operate on objects by default . All others operators can't operate objects . We have to overload them to operate on objects .
// For this reason assignment operator must be overloaded as nonstatic member function . Otherwise it will create ambiguity between the overloaded and the default function . 
// Assignment operator can't be overloaded as static member function , friend function , free function , functions in namespaces .
class Point{
	float x, y;

	// Valid
	Point& operator=(Point& A)
	{
		this->x = A.x;
		this->y = A.y;
		return *this;
	}

	// Invalid
	/*static Point& operator=(Point& A, Point& B)
	{
		A.x = B.x;
		A.y = B.y;
		return A ;
	}*/

	// Invalid
	// friend Point& operator=(Point& A,Point& B);
};

// Invalid
/*Point& operator=(Point& p, Point B)
{

}*/

int main()
{

}