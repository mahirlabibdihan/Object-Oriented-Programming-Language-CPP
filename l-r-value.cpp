// l-value can be used as both l and r value
// r-value can't be used as l value


int R;

// This function can be used as both l-value and r-value
int& Reference()
{
	return R;
}

int main(){
	//rvalue reference
	int a;
	int&& rref=10;
	//lvalue reference
	int& lref=a;
	int& Lref=rref;

	Reference()=a;
}
