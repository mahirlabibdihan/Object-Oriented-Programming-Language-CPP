#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class Coord{
	int x, y;
	char *pointname;
public:
	Coord(){
		x=y=0;
		pointname = new char[100];
	}
	Coord(int x,int y,const char *pointname){
		this->x = x;
		this->y = y;
		strcpy(this->pointname,pointname);
	}
	Coord(const Coord& c){
		this->x = c.x;
		this->y = c.y;
		this->pointname = new char[100];
		strcpy(this->pointname,c.pointname);
	}
	Coord(const int& n,const Coord& c){

	}

	Coord operator+(const Coord& c){
		Coord temp;
		temp.x = this->x + c.x;
		temp.y = this->y + c.y;
		return temp;
	}
	// friend Coord operator+(const int& n,const Coord& c);
	friend int operator+(const int& n,const Coord& c);
	static void main(){
		Coord ob1,ob2,ob3;
		Coord ob4(0,0,"origin");
		ob1 = ob2 + ob3 + ob4;
		ob1 = 100 + ob2;
		int value = 100 + ob4;
	}
};
Coord operator+(const int& n,const Coord& c){
	Coord temp;
	temp.x = c.x + n;
	temp.y = c.y + n;
	return temp;
}
int operator+(const int& n,const Coord& c){
	int temp=sqrt(c.x*c.x+c.y*c.y);
	return temp+n;
}
int main(){Coord::main();}