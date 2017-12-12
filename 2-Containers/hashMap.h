#pragma once
#include "tvector.h"
#include "intvector.h"

template<typename T>
class hashMap
{
private:
	tVector<T> vector;
public: 

	size_t hash(T value)
	{
		size_t hashCode = 0;
		while (containsKey(hashCode) == true || hashCode == 0)
		{
			hashCode = value % vector.getCapacity();
		}
		return hashCode;
	}
		
	void clear()
	{
		vector.clear();
	}

	bool containsKey(size_t key)
	{
		if (vector.at(key) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	T get(size_t key)
	{
		return vector.at(key);
	}

	bool empty() const
	{
		return vector.empty()
	}

	void put(T value)
	{
		size_t idx = hash(value);

		vector.insert(idx, value);

	}

	void remove(size_t key)
	{
		vector.erase(key);
	}

	int size() const
	{
		return vector.getSize();
	}

};