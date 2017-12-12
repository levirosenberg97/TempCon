#pragma once
template <typename T>
class intLinkedList
{
public:
	struct intLinkedListNode
	{
		T value;
		intLinkedListNode * next;
		intLinkedListNode * prev;
	};

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

	void intLinkedList::append(T value)
	{
		intLinkedListNode * newNode = new intLinkedListNode;
		newNode->value = value;
		newNode->next = nullptr;
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
			newNode->prev = iter;
			iter->next = newNode;
		}
	}

	T intLinkedList::at(T index)
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

	int intLinkedList::size() const
	{
		intLinkedListNode* iter = head;
		if (iter == nullptr)
		{
			return 0;
		}
		int counter = 1;


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

	T intLinkedList::front() const
	{
		assert(head != nullptr);
		return head->value;
	}

	T intLinkedList::back() const
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
		assert(head != nullptr);
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
		assert(!empty());
		intLinkedListNode * iter = head;
		assert(idx < size());
		int counter = 0;




		while (iter->next != nullptr && counter != idx)
		{
			iter = iter->next;

			counter++;

		}

		assert(idx == counter);




		if (idx == 0)
		{
			head = iter->next;
			head->prev = nullptr;
		}
		else
		{
			iter->prev->next = iter->next;
		}

		delete iter;
	}

	int intLinkedList::count(T sum) const
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

	void intLinkedList::insert(T num, size_t idx)
	{
		intLinkedListNode* iter = head;
		intLinkedListNode* newItem = new intLinkedListNode;
		intLinkedListNode* temp = head;
		newItem->value = num;
		size_t counter = 0;
		while (iter != nullptr)
		{
			if (counter == idx - 1)
			{
				temp = iter;
			}

			if (counter == idx)
			{
				temp->next = newItem;
				newItem->next = iter;

			}
			counter++;
			iter = iter->next;


		}
	}


};