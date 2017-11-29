#pragma once

class intVector
{
	int * data;	     // ptr to your dynamically allocated array
	size_t capacity; // total size ( or rather, the capacity )
	size_t size;     // total number of elements stored

public:

	intVector();
	~intVector();

	int & at(size_t idx);

	int & append(int val);
	int* dataPtr() const;
	size_t curCapacity() const;
	size_t curSize() const;
	bool empty() const;
	int front() const;
	int back() const;
	
	int operator[](size_t idx)const;
	int &operator[](size_t idx);
	void clear();
	void erase(size_t idx);
	int count(int num)const;
	void insert(size_t idx, int num);
	void Reserve(size_t newCapacity);
	void Compact();

	void printVector();


private: 
	bool grow(size_t minSize);
};