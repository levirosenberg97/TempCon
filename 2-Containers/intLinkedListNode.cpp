#include "intlinkedlist.h"
#include<cassert>

intLinkedList::intLinkedList()
	: head(nullptr)
{

}

intLinkedList::~intLinkedList()
{
	intLinkedListNode * iter = head;

	while (iter != nullptr)
	{
		intLinkedListNode * next = iter->next;
		delete iter;
		iter = next;
	}
}

void intLinkedList::append(int value)
{
	intLinkedListNode * newNode = new intLinkedListNode;
	newNode->value = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		intLinkedListNode * iter = head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}

		iter->next = newNode;
	}
}

int intLinkedList::at(size_t index)
{
	intLinkedListNode* iter = head;
	int counter = 0;

	while (counter != index && iter != nullptr)
	{
		counter++;
		iter = iter->next;
	}

	assert(iter != nullptr);

	return iter->value;
}

size_t intLinkedList::size() const
{
	intLinkedListNode* iter = head;
	if (iter == nullptr)
	{
		return 0;
	}
	size_t counter = 1;
	
	
	while (iter->next != nullptr)
	{
		counter++;
		iter = iter->next;
	}
	
	return counter;
}

bool intLinkedList::empty() const
{
	return head == nullptr;
}

int intLinkedList::front() const
{
	assert(head != nullptr);
	return head->value;
}

int intLinkedList::back() const
{
	assert(!empty());
	intLinkedListNode* iter = head;

	while (iter->next != nullptr)
	{
		iter = iter->next;
	}

	return iter->value;
}

void intLinkedList::clear()
{
	//head = nullptr;
	intLinkedListNode * iter = head;

	while (iter != nullptr)
	{
		intLinkedListNode * next = iter->next;
		delete iter;
		iter = next;
	}
	head = nullptr;
}

void intLinkedList::erase(size_t idx)
{
	intLinkedListNode * iter = head;
	assert(idx <= size());
	int counter = 0;
	intLinkedListNode* temp = iter;
	while (iter->next != nullptr && counter != idx)
	{
		counter++;
		temp = iter;
		iter = iter->next;
		/*if (counter == idx)
		{
			delete iter;
		}*/
	}

	assert(idx == counter);

	 
	temp->next = iter->next;
	delete iter;

	//iter = iter->next->next;
}

int intLinkedList::count(int sum) const
{
	intLinkedListNode* iter = head;
	int counter = 0;
	while (iter != nullptr)
	{
		
		if (iter->value == sum)
		{
			counter++;
		}
		iter = iter->next;
	}
	return counter;
}

void intLinkedList::insert(int num, size_t idx)
{
	intLinkedListNode* iter = head;
	intLinkedListNode* newItem = new intLinkedListNode;
	intLinkedListNode* temp = head;
	newItem->value = num;
	int counter = 0;
	while (iter != nullptr)
	{
		if (counter == idx-1)
		{
			temp = iter;
		}

		if (counter == idx)
		{
			temp->next = newItem;
			newItem->next = iter;
		//	iter->next->value = iter->value;
		//	iter->value = num;
			
		}
		counter++;
		iter = iter->next;
		
	}
}