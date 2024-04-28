#pragma once
template<typename T>
class PriorityQueue
{
public:
	virtual ~PriorityQueue(){}
	virtual void insert(T element, int priority) = 0;
	virtual T extract_max() = 0;
	virtual T find_max() = 0;
	virtual void modify_key(T element, int priority) = 0;
	virtual void decrease_key(T element) = 0;
	virtual void increase_key(T element) = 0;
	virtual int getSize() = 0;
};