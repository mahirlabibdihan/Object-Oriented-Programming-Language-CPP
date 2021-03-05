int main()
{
	int *x=new int[100];
	if(!x) return 0; 
	delete[] x;
}