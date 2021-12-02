#include<iostream>
#include<thread>
using namespace std;

void Count(int n,int &s)
{
	for(int i=n;i<n+10;i++)
	{
		s+=i;
		cout<<s<<endl;
	}
}
int main()
{
	int s=0;
	thread t1(Count,1,ref(s)),t2(Count,11,ref(s)),t3(Count,21,ref(s)),t4(Count,31,ref(s)),t5(Count,41,ref(s));

	t1.join();	// Main thread waits for t1 to finish
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	cout<<s;
}