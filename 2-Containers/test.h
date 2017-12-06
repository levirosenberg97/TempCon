#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#pragma warning(2:4235)  

class Person
{
public:
	int age;
	int height;
	std::string name;

};

static int add(int a, int b)
{
	return a + b;
}

static float add(float a, float b)
{
	return a + b;
}

template<typename T>
static T sub(T a, T b)
{
	return a - b;
}

template<typename T>
static void print(T a)
{
	std::cout << a << endl;
}

template<>
static void print(Person value)
{
	std::cout << value.name << std::endl;
	std::cout << value.age << std::endl;
	std::cout << value.height << std::endl;
}

template<typename T>
static T min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
static T max(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
static T clmp(T a, T b, T c)
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
static void swp(T &a, T &b)
{
	T buffer = a;
	a = b;
	b = buffer;
}

template<>
static char min(char a, char b)
{
	return a < b ? a : b;
}

template<>
static char max(char a, char b)
{
	return a > b ? a : b;
}

template <bool checker>
static bool compare(bool b)
{
	if (checker == b)
	{
		return true;
	}

	return false;
}

template <typename T>
static T eql(T a, T b)
{
	if (a != b)
	{
		abort;
	}

	return 0;
}

template <typename T>
static T noteql(T a, T b)
{
	if (a == b)
	{
		abort;
	}

	return 0;
}