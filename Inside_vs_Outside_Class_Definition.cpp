// The member functions defined inside a class definition are by default inline functions.
class C1
{
public:
	// Inline function
	void f()	// inline void f()
	{

	}
};

class C2
{
public:
	void f();
};


// This definition can be in different file
// Normal function
void C2::f()
{

}

class C3
{
public:
	void f1();
	inline void f2();
	inline void f3();

};


// This definition must be in same file
// Inline functions
inline void C3::f1()
{

}

void C3::f2()
{

}

inline void C3::f3()
{

}


int main()
{
	C3 c;
	c.f();
}