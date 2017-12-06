#pragma once
#include "intvector.h"
#include<assert.h>
#include"test.h"
#include"iterator.h"
template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;
	
public:
	tVector()
	{
		capacity = 2;
		data = new T[capacity];
		size = 0;
	}
	~tVector()
	{
		delete[] data;
	}

	iterator<tVector<T>> begin()
	{
		return iterator<tVector<T>>(*this, 0);
	}

	iterator<tVector<T>> end()
	{
		return iterator<tVector<T>>(*this, size);
	}


	T& at(size_t idx)
	{
		assert(idx >= 0);
		assert(idx < size);

		return data[idx];
	}

	T& append(T val)
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

	T* c_ptr() const
	{
		return data;
	}

	size_t getCapacity() const
	{
		return capacity;
	}

	size_t getSize() const
	{
		return size;
	}

	bool empty() const
	{
		return size == 0;
	}

	T front() const
	{
		return data[0];
	}

	T back() const
	{
		return data[size - 1];
	}

	void pop()
	{
		assert(size > 0);
		size--;
	}
	
	T operator[](size_t idx)const
	{
		assert(idx < size);
		return data[idx];
	}

	T &operator[](size_t idx)
	{
		assert(idx < size);
		return data[idx];
	}

	void clear()
	{
		size = 0;
	}

	void erase(size_t idx)
	{
		for (size_t i = idx; i < size; i++)
		{
			swp(data[i], data[i + 1]);
		}
		size--;
	}

	size_t count(T num)const
	{
		size_t counter = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (data[i] == num)
			{
				counter++;
			}
		}

		return counter;
	}

	void insert(size_t idx, T num)
	{
		grow(size + 1);
		size++;
		T buffer = data[idx];
		data[idx] = num;

		for (size_t i = idx; i < size; i++)
		{
			swp(data[i + 1], buffer);
		}
	}

	void Reserve(size_t newCapacity)
	{
		if (newCapacity > capacity)
		{
			T *newData = new T[newCapacity];
			memcpy(newData, data, sizeof(T) * size);
			delete[] data;
			data = newData;
			capacity = newCapacity;

		}
	}

	void Compact()
	{
		if (capacity > size)
		{
			T * newData = new T[size];
			memcpy(newData, data, sizeof(T) * size);

			delete[] data;

			data = newData;
			capacity = size;
		}
	}

	void eraseRange(size_t start, size_t end)
	{
		size_t dis = (end - start) + 1;

		for (size_t i = 0 ; i < dis; i++)
		{
			if (end + 1 + i >= size)
			{
				break;
			}
			swp(data[start + i], data[end + 1 + i]);
		} 


		size -= dis;
	}

	void printVector()
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << data[i] << std::endl;
		}
	}

private:
	bool grow(size_t minSize)
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

		T * newData = new T[capacity];
		memcpy(newData, data, sizeof(T) * size);

		delete[] data;

		data = newData;

		return true;
	}
};