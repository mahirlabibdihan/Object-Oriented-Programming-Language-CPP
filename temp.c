#include "stdio.h"
__inline__ void f()
{
	puts("World");
}

void f2()
{
	f();
}