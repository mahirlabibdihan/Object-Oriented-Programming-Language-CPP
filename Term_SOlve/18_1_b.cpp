// If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor for each class which does a bit-wise copy between objects. 

// The default copy constructor does only bitwise or shallow copy. 

// If the class has pointer variables and dynamic memory allocations then bitwise copy is not enough

// Default copy constructor will create problem, If your class contains pointer members, which are dynamically allocated.

// When an object with pointer member is copied to another object with default copy constructor, then both object's member will point to the same location.

// So, when destructor of an object is called it will creates problem

class Animal{
	int *a;
public:
	Animal(){
		a = new int;
	}
	Animal(const Animal& a){
		this->a = new int;
		*this->a = *a.a;
	}
	~Animal(){
		delete a;
	}
};

int main(){
	Animal a;
	Animal b(a);
}