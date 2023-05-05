#pragma once

#include <iostream>
#include <list>
#include <exception>

//struct MyComparator
//{
//	int operator()(int a, int b) const {
//		return a - b;
//	}
//
//};

template <typename T>
struct MyComparator
{
	T operator()(T a, T b) const {
		return a - b;
	}

};

template <typename T>
class PriorityQueue
{
public:
	void push(const T& t)
	{
		auto iterator = _data.begin();
		// Find the location to insert t as the list's value are from small to big. 
		while (iterator != _data.end() && cmp(*iterator, t) < 0)
			iterator++;

		_data.insert(iterator, t);
	}
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
