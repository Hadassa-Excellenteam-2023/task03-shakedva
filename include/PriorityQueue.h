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
	T operator()(T a, T b) const {
		return a - b;
	}
};

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue() = default;
	~PriorityQueue() = default;

	// Push new element into the priority queue.
	void push(const T& t)
	{
		auto iterator = _data.begin();
		// Find the location to insert as the list's value are from small to big. 
		while (iterator != _data.end() && cmp(*iterator, t) < 0)
			iterator++;

		_data.insert(iterator, t);
	}
	// Returns and takes out the smallest value from the priority queue.
	T poll()
	{
		if (_data.empty())
			throw std::out_of_range("PriorityQueue is empty");
		
		T val = _data.front();
		_data.pop_front();
		return val;
	}

private:
	std::list<T> _data;
	MyComparator<T> cmp;
};
