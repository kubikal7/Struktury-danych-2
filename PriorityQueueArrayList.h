#pragma once
#include <iostream>
#include "PriorityQueue.h"
#include "PQAL_element.h"
#include "ArrayList.h"

using namespace std;

template<typename T>
class PriorityQueueArrayList : public PriorityQueue<T>
{
	ArrayList<PQAL_element<T>> list;
public:
	void insert(T element, int priority) {										//adds element to heap and find proper index for it
		int i = 0;
		int size = list.getSize();
		while (list.getElement(i).getPriority() >= priority && i < size) {
			i++;
		}
		PQAL_element<T> el(element, priority);
		list.addElement(el, i);
	}

	T extract_max() {															//returns max (top) element - first element in array
		return list.pop_front().getElement();
	}

	T find_max() {																//only returns max (top) element without remove it
		return list.getElement(0).getElement();
	}

	void modify_key(T element, int priority) {									//edits priority of element in array
		int size = list.getSize();
		int i = 0;
		while (i < size && list.getElement(i).getElement() != element) {		//looking for index of element
			i++;
		}
		if (i == size) {
			cout << "Element not found";
			return;
		}
		list.getElement(i).setPriority(priority);
	}

	void decrease_key(T element){												//the same like modify_key but only change -1
		int size = list.getSize();
		int i = 0;
		while (i < size && list.getElement(i).getElement() != element) {
			i++;
		}
		if (i == size) {
			cout << "Element not found";
			return;
		}
		T el = list.getElement(i).getElement();
		int prio = list.getElement(i).getPriority();
		list.deleteElement(i);
		insert(el, --prio);
	}

	void increase_key(T element){												//the same like modify_key but only change +1
		int size = list.getSize();
		int i = 0;
		while (i < size && list.getElement(i).getElement() != element) {
			i++;
		}
		if (i == size) {
			cout << "Element not found";
			return;
		}
		T el = list.getElement(i).getElement();
		int prio = list.getElement(i).getPriority();
		list.deleteElement(i);
		insert(el, ++prio);
	}

	int getSize() {
		return list.getSize();
	}

	void print() {
		for (int i = 0; i < list.getSize(); i++) {
			cout << list.getElement(i).getElement();
		}
	}
};