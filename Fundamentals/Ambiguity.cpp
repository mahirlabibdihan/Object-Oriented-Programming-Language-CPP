/** 1 **/
	// The return type alone is not a sufficient difference to allow function overloading
	// This is a compile error
	// double sum(int x,int y,int z)
	// {
	// 	return x+y+z;
	// }

	// int sum(int x,int y,int z)
	// {
	// 	return x+y+z;
	// }

	/** 2 **/
	// Due to identical parameter types
	// This is not a compile error until we call this functions
	// double sum(float x,float y)
	// {
	// 	return x+y;
	// }

	// double sum(int x,int y)
	// {
	// 	return x+y;
	// }
	/*
		It will create ambiguity if we call sum(3.5,5.6) 
		The reason behind the ambiguity in above code is that the floating literals 3.5 and 5.6 are actually treated as double by the compiler. 
		As per C++ standard, floating point literals (compile time constants) are treated as double unless explicitly specified by a suffix. Since compiler could not find a function with double argument and got confused if the value should be converted from double to int or float.
	*/

	/** 3 **/
	// Due to the use of default arguments
	// This is not a compile error until we call this functions
	// int sum(int x,int y,int z,int w=0)
	// {
	// 	return x+y+z+w;
	// }

	// int sum(int x,int y,int z)
	// {
	// 	return x+y+z;
	// }

	/** 4 **/
	// Due to the use of reference parameters
	// This is not a compile error until we call this functions
	// int sum(int x,int y){
	// 	return x+y;
	// }

	// int sum(int x,int &y)
	// {
	// 	return x+y;
	// }