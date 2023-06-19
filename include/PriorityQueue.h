#pragma once

#include <iostream>
#include <list>
#include <exception>

template <typename T>
struct MyComparator
{
	/*
	* Compare two values, returns their difference. 
	* a > b		positive difference
	* a == b	zero
	* a < b		negative difference
	*/
	T operator()(const T& a, const T& b) const {
		return a - b;
	}
};

template <typename T>
class PriorityQueue
{
public:

	// Push new element into the priority queue.
	void push(const T& t)
	{
		auto iterator = _data.cbegin();
		// Find the location to insert the element
		while (iterator != _data.cend() && cmp(*iterator, t) < 0)
			iterator++;

		_data.insert(iterator, t);
	}
	// Returns and takes out the smallest value from the priority queue.
	T poll()
	{
		if (_data.empty())
			throw std::logic_error("PriorityQueue is empty");
		
		T val = _data.front();
		_data.pop_front();
		return val;
	}

private:
	std::list<T> _data;
	MyComparator<T> cmp;
};
