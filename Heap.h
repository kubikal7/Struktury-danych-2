#pragma once
#include "ArrayList.h"
#include "PQAL_element.h"


template<typename T>
class Heap : public PriorityQueue<T> {
    ArrayList<PQAL_element<T>> elements;

    void swap(int index1, int index2) {                                 //swap elements between index1 and index2
        PQAL_element<T>& element1 = elements.getElement(index1);
        PQAL_element<T>& element2 = elements.getElement(index2);
        PQAL_element<T> temp = element1;
        element1 = element2;
        element2 = temp;
    }

    void bubbleUp(int index) {                                          //while parent's priority is smaller swap parrent and index
        while (index > 0 && elements.getElement((index - 1) / 2).getPriority() < elements.getElement(index).getPriority()) {
            swap(index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }

    void bubbleDown(int index) {                                        //while child's priority is bigger swap child and index
        int size = elements.getSize();
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && elements.getElement(leftChild).getPriority() > elements.getElement(largest).getPriority()) {
            largest = leftChild;
        }
        if (rightChild < size && elements.getElement(rightChild).getPriority() > elements.getElement(largest).getPriority()) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(index, largest);
            bubbleDown(largest);
        }
    }

    int find_element_index(T element) {                             //looking for index of element in heap
        for (int i = 0; i < elements.getSize(); i++) {
            if (elements.getElement(i).getElement() == element) {
                return i;
            }
        }
        return -1;                                                  // Element not found
    }

public:
    void insert(T element, int priority) {                          //adds element to heap and find proper index for it 
        PQAL_element<T> newElement(element, priority);
        elements.push_back(newElement);
        bubbleUp(elements.getSize() - 1);
    }

    T extract_max() {                                               //returns max (top) element
        if (elements.getSize() == 0) {
            cout << "Heap is empy";
        }
        T maxElement = elements.getElement(0).getElement();
        elements.getElement(0) = elements.getElement(elements.getSize() - 1);      //gives last element on top and then bubbleDown for it
        elements.pop_back();
        bubbleDown(0);
        return maxElement;
    }

    T find_max() {                                                  //only returns max (top) element without remove it
        if (elements.getSize() == 0) {
            cout << "Heap is empy";
        }
        return elements.getElement(0).getElement();
    }

    int getSize() {
        return elements.getSize();                              
    }

    void modify_key(T element, int newPriority)  {                   //edits priority of element in heap
        int index = find_element_index(element);
        
        if (index == -1) {
            cout<<"Element not found"<<endl;
        }

        int currentPriority = elements.getElement(index).getPriority();
        elements.getElement(index).setPriority(newPriority);

        if (newPriority > currentPriority) {                        //if priority is bigger than previous do bubbleUp
            bubbleUp(index);
        }
        else {
            bubbleDown(index);                                      //if priority is smaller than previous do bubbleDown
        }
    }

    void decrease_key(T element) {                                  //the same like modify_key but only change -1
        int index = find_element_index(element);

        if (index == -1) {
            cout << "Element not found" << endl;
        }

        int currentPriority = elements.getElement(index).getPriority();
        elements.getElement(index).setPriority(currentPriority-1);

        
        bubbleUp(index);
    }

    void increase_key(T element) {                                  //the same like modify_key but only change +1
        int index = find_element_index(element);

        if (index == -1) {
            cout << "Element not found" << endl;
        }

        int currentPriority = elements.getElement(index).getPriority();
        elements.getElement(index).setPriority(currentPriority + 1);


        bubbleDown(index);
    }

    void print() {
        for (int i = 0; i < elements.getSize(); i++) {
            cout << elements.getElement(i).getElement();
        }
    }
};
