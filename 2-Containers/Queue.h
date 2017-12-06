#pragma once
#include "intlinkedlist.h"

template <typename T>
class Queue
{
private:
	intLinkedList list;
public:
	//front is your head

	//empty
	bool empty()
	{
		return list.empty();
	}


	//size
	T size()
	{
		return list.size();
	}

	//push
	void push(T value)
	{
		list.append(value);
	}

	//pop
	T pop()
	{
		T buffer = list.at(0);
	
		list.erase(0);
		return buffer;
	}
	//-return the thing that was popped


	//front
	T front()
	{
		return list.front();
	}
	//-access the front element
	//back
	T back()
	{
		return list.back()
	}

};