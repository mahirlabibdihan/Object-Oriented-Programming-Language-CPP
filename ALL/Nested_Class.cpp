class A{
	static int j;
	int a;
	void show(){
		
	}
	class B{
		static int i;
		void run(){
			// a;	// Inner class method's can't access non-static data-member/method of outer class
			// show();
		}
	};

	// This means x is static. Not class C. Can't use static before a class name without variable. 
	static class C{

	}x;	
};

int A::j;
int A::B::i;

int main(){

}