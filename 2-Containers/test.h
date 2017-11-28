#pragma once
#include <cstdlib>
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
bool compare(bool b)
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