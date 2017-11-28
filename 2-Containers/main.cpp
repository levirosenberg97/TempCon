#include"intvector.h"
#include "test.h"
int main()
{
	intVector nums;

	nums.append(1);
	nums.append(4);
	nums.append(4);
	nums.append(4);
	nums.append(5);

	nums.erase(3);

	nums.printVector();
	int howManyFours = nums.count(4);
	
	nums.insert(2, 4);

	eql(howManyFours, 3);
	nums.Reserve(50);
	eql((int)nums.curCapacity(), 50);
	nums.Compact();


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

	return 0;
}