#pragma once
#include "ArrayList.h"
#include "PQAL_element.h"
#include <stdexcept>

template<typename T>
class Heap {
    ArrayList<PQAL_element<T>> elements;

    void bubbleUp(int index) {
        while (index > 0 && elements.getElement((index - 1) / 2).getPriority() < elements.getElement(index).getPriority()) {
            std::swap(elements.getElement(index), elements.getElement((index - 1) / 2));
            index = (index - 1) / 2;
        }
    }

    void bubbleDown(int index) {
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
            std::swap(elements.getElement(index), elements.getElement(largest));
            bubbleDown(largest);
        }
    }

public:
    void insert(T element, int priority) {
        PQAL_element<T> newElement(element, priority);
        elements.push_back(newElement);
        bubbleUp(elements.getSize() - 1);
    }

    T extract_max() {
        if (elements.getSize() == 0) {
            throw std::runtime_error("Heap is empty");
        }
        T maxElement = elements.getElement(0).getElement();
        elements.getElement(0) = elements.getElement(elements.getSize() - 1);
        elements.pop_back();
        bubbleDown(0);
        return maxElement;
    }

    T find_max() const {
        if (elements.getSize() == 0) {
            throw std::runtime_error("Heap is empty");
        }
        return elements.getElement(0).getElement();
    }

    int getSize() const {
        return elements.getSize();
    }
};
