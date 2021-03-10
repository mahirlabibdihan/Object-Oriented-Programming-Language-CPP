#include "stdio.h"
void f2();
inline void f()
{
	puts("Hello");
}
int main()
{
	f();
	f2();
}