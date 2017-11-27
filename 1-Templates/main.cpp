#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	int age;
	int height;
	string name;

};

int add(int a, int b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

template<typename T>
T sub(T a, T b)
{
	return a - b;
}

template<typename T>
void print(T a)
{
	cout << a << endl;
}

template<>
void print(Person value)
{
	cout << value.name << endl;
	cout << value.age << endl;
	cout << value.height << endl;
}

template<typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
T clmp(T a, T b, T c)
{
	T sml = min(a, b);
	T lrg = max(a, b);

	if (c >= lrg)
	{
		return lrg;
	}
	else if (c <= sml)
	{
		return sml;
	}
	else
	{
		return c;
	}
}

template<typename T>
void swp(T &a, T &b)
{
	T buffer = a;
	a = b;
	b = buffer;
}

template<>
char min(char a, char b)
{
	return a < b ? a : b;
}

template<>
char max(char a, char b)
{
	return a > b ? a : b;
}

template <bool checker>
bool compare( bool b)
{
	if (checker == b)
	{
		return true;
	}
	
	return false;
}

template <typename T>
T eql(T a, T b)
{
	if (a != b)
	{
		_asm int 3;
	}

	return 0;
}

template <typename T>
T noteql(T a, T b)
{
	if (a == b)
	{
		_asm int 3;
	}

	return 0;
}

int main()
{

	int v1 = add(5, 2);
	float v2 = add(2.1f, 3.2f);

	int s1 = sub(1, 1);
	float s2 = sub(2.5f, 1.1f);
	int s3 = sub<int>(1, 2.0f);

	// ==CLOSED==
	// 1.Print Function
	print(true);

	// 2.Common Math Operations
	int sml = min(3,34 );
	print(sml);

	int lrg = max(31, 3);
	print(lrg);

	int num = clmp(32, 6, 8);
	print(num);

	// 3.Explicit Print Function Instantiation for User-Defined Type(Person)
	Person me;

	me.name = "Levi";
	me.age = 20;
	me.height = 76;

	print(me);

	// ==OPEN==
	// 1.Swap
	swp(v1, s1);

	// 2.Min and Max Instantiations for Char Types
	char lower = min('a', 'f');
	char higher = max('a', 'f');
	
	// 3.Templated Assertions

	// Boolean Assertions
	bool dead = true;
	bool result = compare<false>(dead);

	// Equal
	int num1 = 1;
	int num2 = 1;

	eql(num1, num2);
	noteql(s1, v1);

	while (true) {}
}
