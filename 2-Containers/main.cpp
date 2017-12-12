#include"intvector.h"
#include "test.h"
#include "tvector.h"
#include <iostream>
#include"intlinkedlist.h"
#include"algorithms.h"
#include"iterator.h"
#include<vector>
#include<list>
#include"Stack.h"
#include"Queue.h"

#include"hashMap.h"


int main()
{
	hashMap<int> hashbrowns;

	hashbrowns.put(34);

	bool plsWork = hashbrowns.containsKey(3);

	/*Stack<int> pan;
	pan.push(0);
	pan.push(1);
	pan.push(2);
	pan.push(3);
	pan.push(4);

	int siz = pan.size();
	int corn = pan.pop();
	
	int top = pan.Top();
	pan.pop();
	pan.pop();
	pan.pop();
	pan.pop();

	bool not = pan.empty();

	Queue<int> pax;
	pax.push(0);
	pax.push(1);
	pax.push(2);
	pax.push(3);

	bool pls = pax.empty();
	int zis = pax.size();
	int woop = pax.pop();
	int boop = pax.front();*/

	/*tVector<int> nums;
	nums.append(1);
	nums.append(3);
	nums.append(5);
	nums.append(7);
	nums.append(9);

	auto begin = nums.begin();
	auto end = nums.end();

	int total = addRange<iterator<tVector<int>>, int>(begin, end);

	int arrayOfNums[] = { 1,3,5,7,9 };
	int total2 = addRange<int*, int>(arrayOfNums, arrayOfNums + 5);
	

	int nums[] = { 1,3,5,7,9 };
	int * start = nums;
	int * end = nums + 4;

	addRange(start, end);


	 intLinkedList list;
	
	 
		 list.append(1);
		 list.append(2);
		 list.append(3);
		 list.append(4);

	 
	 
	

	//tVector<int> val;
	nums.append(1);
	nums.append(4);
	nums.append(4);
	nums.append(4);
	nums.append(5);
	nums.append(1);
	nums.append(4);
	nums.append(4);
	nums.append(4);
	nums.append(5);*/

	/*nums.erase(3);
*/
	//nums.printVector();
	//int howManyFours = nums.count(4);
	//
	////nums.insert(2, 4);

	////eql(howManyFours, 3);
	////nums.Reserve(50);
	////eql((int)nums.curCapacity(), 50);
	//nums.Compact();

	//val.append(0);
	//val.append(1);
	//val.append(2);
	//val.append(3);
	//val.append(4);

	//val.pop();
	//val.erase(4);
	//val.eraseRange(2, 4);
	//val.insert(3, 9);

	/*val.printVector();*/

	//eql<size_t>(nums.curCapacity(), 2);
	//	
	//nums.append(1);
	//nums.append(5);

	//eql(nums.at(0), 1);
	//eql(nums.at(1), 5);

	//nums.append(33);

	//eql(nums.at(0), 1);
	//eql(nums.at(1), 5);
	//eql(nums.at(2), 33);
	//eql<size_t>(nums.curCapacity(), 4);
	//eql<size_t>(nums.curSize(), 3);
	//compare<false>(nums.empty());
	//eql(nums.front(), 1);
	//eql(nums.back(), 33);
	//eql(nums.dataPtr(), &nums.at(0));
	while (true){}
}