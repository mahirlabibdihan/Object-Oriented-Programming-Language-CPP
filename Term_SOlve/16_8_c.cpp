#include<iostream>
using namespace std;
class A
{
	int x;
public:
	void setX(int i) {x = i;}
	void print() { cout << x; }
};


class B: virtual public A
{
public:
	B() {
		setX(10); }//do not change the parameter value while fixing the code
};

class C: virtual public A
{
public:
	C() { setX(20); }//donot change the parameter value while fixing the code
};
class D: public B, public C {

};


int main() {
	D d;
	d.print();
	return 0;
}