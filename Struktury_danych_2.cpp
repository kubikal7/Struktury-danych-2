#include <iostream>
#include <chrono>
#include <random>
#include "ArrayList.h"
#include "PQAL_element.h"
#include "PriorityQueueArrayList.h"
#include "Heap.h"
#include "PriorityQueue.h"
using namespace std;

void generateQueues(PriorityQueue<int>* q1, PriorityQueue<int>* q2, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 300000);
    for (int i = 0; i < size;i++) {

        int random_value = distr(gen);
        int random_priority = distr(gen);

        q1->insert(random_value, random_priority);
        q2->insert(random_value, random_priority);
    }
}

void generateQueue(PriorityQueue<int>* q1, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 300000);
    for (int i = 0; i < size;i++) {

        int random_value = distr(gen);
        int random_priority = distr(gen);

        q1->insert(random_value, random_priority);
    }
}

int main()
{
    /*PriorityQueue<int>* PQAL = nullptr;                                       //tests
    PriorityQueue<int>* pqHeap=nullptr;
    
    int num = 30;
    double time1 = 0;
    double time2 = 0;
    
    for (int i = 0;i < num;i++) {
        PQAL = new PriorityQueueArrayList<int>;
        pqHeap = new Heap<int>;

        generateQueues(PQAL, pqHeap, 1000);

        auto start1 = chrono::high_resolution_clock::now();
            PQAL->getSize();
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> elapsed1 = end1 - start1;
        time1 += elapsed1.count();
        

        auto start2 = chrono::high_resolution_clock::now();
            pqHeap->getSize();
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> elapsed2 = end2 - start2;
        time2 += elapsed2.count();
       

        delete PQAL;
        delete pqHeap;
    }
    
    cout << "Tablica dynamiczna: " << time1/num << endl;
    cout << "Kopiec: " << time2/num << endl;*/

    PriorityQueue<int>* PriorityQueue = nullptr;                                //creating pointer of PriorityQueue for derived classes

    int structure_type;
    int load_size;
    int action;
    int quit = false;

    while (!quit) {
        cout << "Which structure would you like choose?" << endl;
        cout << "1. Priority Queue as Dynamic Array" << endl << "2. Priority Queue as Heap" << endl;
        cout << "Choose: ";
        cin >> structure_type;

        if (structure_type == 1)
            PriorityQueue = new PriorityQueueArrayList<int>();                  //creating Priority Queue Array List object at Priority Queue pointer
        else if (structure_type == 2)
            PriorityQueue = new Heap<int>();                                    //creating Priority Queue Heap object at Priority Queue pointer
                 

        if (PriorityQueue != nullptr) {

            cout << endl;

            cout << "How many elements would you like generate in Queue?: ";
            cin >> load_size;

            generateQueue(PriorityQueue, load_size);                                                    //generating queue with load_size number elements with random value and random priority in range (1-300 000)
            
            cout << endl;

            while (!quit) {
                cout << "Wchis action would you like choose?" << endl;
                cout << "1. Insert element" << endl << "2. Extract max element" << endl << "3. Find max element" << endl;
                cout << "4. Modify key (priority)" << endl << "5. Get queue size" << endl << endl;
                cout << "6. Change structure" << endl << "7. Reset queue" << endl << "8. Quit program" << endl;
                cout << "Choose: ";
                cin >> action;
                if (action == 1) {
                    int value, priority;
                    cout << "Enter a value of element: ";
                    cin >> value;
                    cout << endl << "Enter a priority of element: ";
                    cin >> priority;
                    auto start = chrono::high_resolution_clock::now();                                  //timer
                    PriorityQueue->insert(value, priority);                                             //adding element to queue
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 2) {
                    auto start = chrono::high_resolution_clock::now();                                  //timer
                    int element = PriorityQueue->extract_max();                                         //return and remove max (top) element
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Extracted max element: " << element << endl;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 3) {
                    auto start = chrono::high_resolution_clock::now();                                  //timer
                    int element = PriorityQueue->find_max();                                            //find max (top) element without remove
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Max element: " << element << endl;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 4) {
                    int element, priority;
                    cout << "Enter a value of element: ";
                    cin >> element;
                    cout << endl << "Enter a priority of element: ";
                    cin >> priority;
                    auto start = chrono::high_resolution_clock::now();                                  //timer
                    PriorityQueue->modify_key(element,priority);                                        //edit priority of element in queue
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 5) {
                    auto start = chrono::high_resolution_clock::now();                                  //timer
                    int size = PriorityQueue->getSize();                                                //return size of priority queue
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Size: " << size << endl;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 6) {
                    delete PriorityQueue;                                                               //deleting list and return to first step in menu
                    break;
                }
                else if (action == 7) {
                    delete PriorityQueue;
                    if (structure_type == 1)
                        PriorityQueue = new PriorityQueueArrayList<int>();                  //creating Priority Queue Array List object at Priority Queue pointer
                    else if (structure_type == 2)
                        PriorityQueue = new Heap<int>();                                    //creating Priority Queue Heap object at Priority Queue pointer

                    generateQueue(PriorityQueue, load_size);

                    cout << "Queue reseted" << endl;
                }
                else if (action == 8) {
                    quit = true;
                }

                cout << endl;
            }
            cout << endl;
        }
    }
    delete PriorityQueue;

    return 0;
}




