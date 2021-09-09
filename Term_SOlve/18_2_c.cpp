#include<iostream>
using namespace std;

class Rational
{
// numerator and denominator
	int n, d;
public:
//Constructor(s) to initialize n and d
	Rational()
	{
		n = 0;
		d = 0;
	}
	Rational(int a, int b)
	{
		n = a;
		d = b;
	}
	friend ostream& operator<<(ostream& out,Rational& r);
};

ostream& operator<<(ostream& out,Rational& r){
	cout<<r.n<<"/"<<r.d<<endl;
	return out;
}
int main(){
	Rational r(3,5);
	cout<<r;
}