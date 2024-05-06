#pragma once
#include "PriorityQueue.h"
#include "Heap.h"

template<typename T>
class PriorityQueueHeap : public PriorityQueue<T> {
private:
    Heap<T> heap;

public:
    void insert(T element, int priority) override {
        heap.insert(element, priority);
    }

    T extract_max() override {
        return heap.extract_max();
    }

    T find_max() override {
        return heap.find_max();
    }

    void modify_key(T element, int newPriority) override {
        int index = find_element_index(element);
        if (index == -1) {
            throw std::runtime_error("Element not found");
        }

        int currentPriority = heap.getElementAt(index).getPriority();
        heap.getElementAt(index).setPriority(newPriority);

        if (newPriority > currentPriority) {
            heap.bubbleUp(index);
        }
        else {
            heap.bubbleDown(index);
        }
    }

    void decrease_key(T element) override {
        modify_key(element, heap.getElementAt(find_element_index(element)).getPriority() - 1);
    }

    void increase_key(T element) override {
        modify_key(element, heap.getElementAt(find_element_index(element)).getPriority() + 1);
    }

    int getSize() override {
        return heap.getSize();
    }

private:
    int find_element_index(T element) {
        for (int i = 0; i < heap.getSize(); i++) {
            if (heap.getElementAt(i).getElement() == element) {
                return i;
            }
        }
        return -1; // Element not found
    }
};
