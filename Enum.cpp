class Animal
{
public:
	enum Name
	{
		Tommy,
		Hulk
	};
};

namespace animal {
enum Name
{
	Tommy,
	Hulk
};
}

enum Name
{
	Tommy,
	Hulk
};
int main()
{
	int a = Animal::Tommy;
	int b = animal::Tommy;
	int c = Tommy;
}