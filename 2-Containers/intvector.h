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

	int operator[](unsigned idx)const;
	int &operator[](unsigned idx);
	void clear();


private: 
	bool grow(size_t minSize);
};