class Object{
};

// new [] => delete[]
// new => delete 
int main()
{
	// type *var = new type;
	// new returns a pointer to dynamically allocated memory that is sufficient to hold a data of type .
	int *a=new int;
	int *b=new int(10);
	// 	In case of insufficient memory, new can report failure in two ways
	// By returning a null pointer
	// By generating an exception
	// The reaction of new in this case varies from compiler to compiler

	// Advantage over malloc : 
	// Do not need to use sizeof operator
	// Automatically returns a pointer of the specified type, do not to use an explicit type cast
	// In case of objects, new dynamically allocates the object and calls its constructor 


	delete a; // releases the memory previously allocated by new . Memory allocated by new must be released using delete .
	// Advantage over free :
	// In case of objects, delete calls the destructor of the object

	// Both new and delete can be overloaded .


	// Object
	Object *obj;	// Doesn't need class definition . Declaration is enough .
	obj = new Object;	// Needs class definition .
	// Array
	int *x = new int[100];
	// Array created with new can't be initialized . Default constructor will ba called .
	delete[] x;
}