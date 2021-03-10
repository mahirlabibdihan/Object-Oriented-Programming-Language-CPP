#include "stdio.h"
void f2();
__inline__ void f()
{
	puts("Hello");
}
int main()
{
	f();
	f2();
}