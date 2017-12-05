#pragma once

class intLinkedList
{
public:
	struct intLinkedListNode
	{
		int value;
		intLinkedListNode * next;
	};

	intLinkedList();
	~intLinkedList();

	void append(int value);

	int at(size_t index);

	size_t size() const;

	bool empty() const;

	int front() const;

	int back() const;

	void clear();

	void erase(size_t idx);

	int count(int sum) const;

	void insert(int num, size_t idx);

private:
	intLinkedListNode * head;


};