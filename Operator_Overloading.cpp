#include <iostream>
using namespace std;
class Point{
private:
	float x,y;

public:
	Point()
	{
		this->x=0;
		this->y=0;
	}
	Point(float x,float y)
	{
		this->x=x;
		this->y=y;
	}
	Point operator+(Point A)
	{
		Point B;
		B.x=this->x+A.x;
		B.y=this->y+A.y;
		return B;
	}

	Point operator=(Point A)
	{
		this->x=A.x;
		this->y=A.y;
		return *this;
	}

	void Print()
	{
		cout<<x<<" "<<y<<endl;
	}
};

class array {
   int a[3];
public:
   array() {
      for(int i=0; i<3; i++)
         a[i] = i;
   }
   int& operator[ ](int i) {
      return a[i];
   }		// both lvalue and rvalue

   // int operator[ ](int i) {
   //    return a[i];
   // }		// Only rvalue

   int F()
   {
   	  return 6;
   }
};


int main()
{
	Point A(3,5),B(4,5);

	A=A+B;

	A.Print();

	array ob;
	ob[0] = 5; // compiler error
	cout<<ob[0];


 	printf("%p\n",&ob.F());
}