// It is possible to access a member of an object via a pointer to that object
// Creation of an object pointer does not create an object
// We can take the address of objects using the address operator (&) and store it in object pointers
// We have to use the arrow (->) operator instead of the dot (.) operator while accessing a member through an object pointer 
// Pointer arithmetic using an object pointer is the same as it is for any other data type
// When incremented, it points to the next object
// When decremented, it points to the previous object
class Animal
{
	
};

int main()
{
	Animal *a;
	// Class definition is not required for creating an object pointer . Because creation of an object pointer does not create an object . And class definition is needed only for object creation .

	a= new Animal;
}
