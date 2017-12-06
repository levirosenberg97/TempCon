#pragma once
#include"tvector.h"
#include<cassert>

template <typename T>
class Stack
{
private:
	tVector<T> vector;
public: 
	//top is size -1
	
	Stack()
	{
		
	}

	//empty
	bool empty()
	{
		return vector.empty();
	}

	//size
	T size()
	{
		return vector.getSize();
	}


	//pop
	T pop()
	{
		assert(!empty());
		T buffer = vector.at(vector.getSize() - 1 );
		vector.erase(vector.at(vector.getSize() - 1));
		return buffer;
	}


	//- return the thing that was popped

	//push
	void push(int value)
	{
		vector.append(value);
	}


	//Top
	int Top()
	{
		return vector.back();
	}

};