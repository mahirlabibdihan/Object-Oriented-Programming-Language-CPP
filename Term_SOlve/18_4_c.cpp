#include<iostream>
using namespace std;
class Date {
	int day, month, year;
public:
	Date(int m, int d, int y) {
		day = d;
		month = m;
		year = y;
	}
	int operator-(const Date& ob){
		return (360*this->year+30*this->month+this->day) - (360*ob.year+30*ob.month+ob.day);
	}
	friend ostream& operator<<(ostream& out,const Date& ob);
};

ostream& operator<<(ostream& out,const Date& ob){
	out<<ob.day<<"-"<<ob.month<<"-"<<ob.year<<endl;
	return out;
}