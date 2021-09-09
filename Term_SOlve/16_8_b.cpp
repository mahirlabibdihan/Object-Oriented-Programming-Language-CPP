#include <iostream>
using namespace std;
int& f();
int x;
int main()
{
f() = 10;
int a=10;
int b=20;
int& ref = a;
ref= b;

cout<< a<<" "<<b<<" "<< ref<<" "<< x;
}
int& f() { return x;}