#pragma once
#include"tvector.h"

template <typename T, typename S>
static S addRange(T start, T end)
{
	S total = 0;
	T iter = start;
	while (iter != end)
	{
		total += *iter;
		iter++;
	}

	return total;
}

template<typename T, typename S>
static S addRangeFinished(T start, T end)
{
	S total = 0;
	T iter = start;
	while (iter != end)
	{
		total += *iter;
		iter++;
	}
	return total;

}

template<typename T>
static auto addRangeComnplex(T start, T end)
{
	std::decay<decltype(*start)>::type total = 0;
	T iter = start;
	while (iter != end)
	{

	}
}
