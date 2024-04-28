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
	void insert(T element, int priority) {
		int i = 0;
		int size = list.getSize();
		while (list.getElement(i).getPriority() >= priority && i < size) {
			i++;
		}
		PQAL_element<T> el(element, priority);
		list.addElement(el, i);
	}

	T extract_max() {
		return list.pop_front().getElement();
	}

	T find_max() {
		return list.getElement(0).getElement();
	}

	void modify_key(T element, int priority) {
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
		list.deleteElement(i);
		insert(el, priority);
	}

	void decrease_key(T element){
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

	void increase_key(T element){
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