#include "intvector.h"
#include <cassert>
#include<cstring>
#include"test.h"
#include <iostream>

intVector::intVector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intVector::~intVector()
{
	delete[] data;
}

int& intVector::at(size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);

	return data[idx];
}

int & intVector::append(int val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}

	data[size] = val;
	size++;
	return data[size - 1];
}

int * intVector::dataPtr() const
{
	return data;
}

size_t intVector::curCapacity() const
{
	return capacity;
}

size_t intVector::curSize() const
{
	return size;
}

bool intVector::empty() const
{
	return size == 0;
}

int intVector::front() const
{
	return data[0];
}

int intVector::back() const
{
	return data[size - 1];
}

int intVector::operator[](size_t idx) const
{
	return data[idx];
}
int & intVector::operator[](size_t idx)
{
	return data[idx];
}

void intVector::clear() 
{
	size = 0;
}

void intVector::erase(size_t idx)
{
	for (size_t i = idx; i < size; i++)
	{
		swp(data[i], data[i + 1]);
	}
	size--;
}

int intVector::count(int num) const
{
	int counter = 0;

	for(size_t i = 0; i < size; i++)
	{
		if (data[i] == num)
		{
			counter++;
		}
	}

	return counter;
}

void intVector::insert(size_t idx, int num)
{
	grow(size + 1);
	size++;
	int buffer = data[idx];
	data[idx] = num;
	
	for (size_t i = idx; i < size; i++)
	{
		swp(data[i + 1], buffer);
	}
}

void intVector::Reserve(size_t newCapacity)
{
	if (newCapacity > capacity)
	{
		int *newData = new int[newCapacity];
		memcpy(newData, data, sizeof(int) * size);
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
}

void intVector::Compact()
{
	if (capacity > size)
	{
		int * newData = new int[size];
		memcpy(newData, data, sizeof(int) * size);
		delete[] data;
		data = newData;
		capacity = size;
	}
}

void intVector::printVector()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << data[i] << std::endl;
	}
}

bool intVector::grow(size_t minSize)
{
	assert(minSize <= 64000);

	if (minSize <= capacity)
	{
		return true;
	}

	while (capacity < minSize)
	{
		capacity *= 2;
	}

	int * newData = new int[capacity];
	memcpy(newData, data, sizeof(int) * size);

	delete[] data;

	data = newData;

	return true;
}