#pragma once

template<typename T>
class PQAL_element
{
	T element;
	int priority;
public:
	PQAL_element(T element, int priority) : element(element), priority(priority) {}

	PQAL_element(){};

	~PQAL_element(){};

	T getElement() {
		return element;
	}

	int getPriority() {
		return priority;
	}

	void setPriority(int value) {
		priority = value;
	}
};