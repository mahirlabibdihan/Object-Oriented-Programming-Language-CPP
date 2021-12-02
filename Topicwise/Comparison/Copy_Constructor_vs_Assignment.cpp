// Animal a = b;   // Copy constructor 
// a = b;  // Assignment

// Why does copy constructor work for initialization, but not for assignment?
// The copy constructor is used to create a new object while the copy assignment operator is used to change an already existent object. As we know, constructors are used to create objects. Not to change existent object.