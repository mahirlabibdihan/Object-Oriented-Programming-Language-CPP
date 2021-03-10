#include<iostream>
#include<cstring>
using namespace std;
class String{
	char *s;
	int currentLength;
public:
	String()
	{
		s=new char[0];
		currentLength=0;
	}
	~String()
    {
        delete[] s;
    }
    int length()
    {
        return currentLength;
    }
    void in()
    {
    	scanf("\n%[^\n]",s);
    	while((getchar()) != '\n');
    }
    void out()
    {
    	puts(s);
    }
    void push_back(char c)
    {
        char* temp = new char[++currentLength];
        for (int i = 0; i < currentLength - 1 ; i++)
        {
            temp[i] = s[i];
        }
        delete[] s;
        s = temp;
        s[currentLength - 1] = c;
    }
    void push_front(char c)
    {
        char* temp = new char[++currentLength];
        for (int i = 1; i < currentLength ; i++)
        {
            temp[i] = s[i];
        }
        delete[] s;
        s = temp;
        s[0] = c;
    }
    void pop_back()
    {
        if (currentLength == 0)
        {
        }
        else
        {
            currentLength--;
        }
    }
    void pop_front()
    {
        if (currentLength == 0)
        {
        }
        else
        {
        	currentLength--;
        	for (int i = 0; i < currentLength ; i++)
	        {
	            s[i]=s[i+1];
	        }
        }
    }
    char back()
    {
    	return s[currentLength-1];
    }
    char front()
    {
    	return s[0];
    }
    char charAt(int index)
    {
    	return s[index];
    }
    bool empty()
    {
        return currentLength == 0;
    }
    char& operator[](char index)
    {
        return s[index];
    }
    char* operator=(char* str)
    {
    	s=new char[strlen(str)];
    	for(int i=0;str[i]!='\0';i++)
    	{
    		s[i]=str[i];
    	}
    	return str;
    }
    void operator+=(char c)
    {
    	char* temp = new char[++currentLength];
        for (int i = 0; i < currentLength - 1 ; i++)
        {
            temp[i] = s[i];
        }
        delete[] s;
        s = temp;
        s[currentLength - 1] = c;
    }
    // String operator+(char c)
    // {
    // 	char* temp = new char[++currentLength];
    //     for (int i = 0; i < currentLength - 1 ; i++)
    //     {
    //         temp[i] = s[i];
    //     }
    //     temp[currentLength - 1] = c;

    //     String str=temp;
    //     return str;
    // }
    void operator--()
    {
    	if (currentLength == 0)
        {
        }
        else
        {
            currentLength--;
        }
    }
    void operator--(int)
    {
    	if (currentLength == 0)
        {
        }
        else
        {
        	currentLength--;
        	for (int i = 0; i < currentLength ; i++)
	        {
	            s[i]=s[i+1];
	        }
        }
    }
};

int main()
{
	String s;
	s.push_back('a');
	s[0]='b';

	cout<<s[0]<<endl;
	s--;
	--s;
}