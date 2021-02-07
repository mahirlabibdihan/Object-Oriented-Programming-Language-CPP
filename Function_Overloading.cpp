int sum(int x,int y)
{
	return x+y;
}

// Two or more functions can share the same name as long as either

// The type of their arguments differs, or
double sum(double x,double y)
{
	return x+y;
}

// The number of their arguments differs
int sum(int x,int y,int z)
{
	return x+y+z;
}

// Ambiguity

// The return type alone is not a sufficient difference to allow function overloading
// double sum(int x,int y,int z)
// {
// 	return x+y+z;
// }


// Due to the use of default arguments
// int sum(int x,int y,int z,int w=0)
// {
// 	return x+y+z+w;
// }


// Due to the use of reference parameters
// int sum(int x,int &y)
// {
// 	return x+y;
// }


// Constructor can be overloaded
// Destructor can't be overloaded

int main(int argc,char *argv[])
{
	int a=sum(1,2,3);
	int b=sum(1,2);
}

