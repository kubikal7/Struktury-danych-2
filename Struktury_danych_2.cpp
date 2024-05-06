#include <iostream>
#include "ArrayList.h"
#include "PQAL_element.h"
#include "PriorityQueueArrayList.h"
#include "PriorityQueueHeap.h"
using namespace std;

int main()
{
    PriorityQueueArrayList<int> PQAL;
    PQAL.insert(10, 10);
    PQAL.insert(1, 4);
    PQAL.insert(2, 5);
    PQAL.increase_key(1);

    /*while (PQAL.getSize() > 0) {
        cout << PQAL.extract_max()<<endl;
    }*/
    PQAL.print();
    PriorityQueueHeap<int> pqHeap;  // Tworzenie instancji kolejki priorytetowej opartej na kopcu

    // Wstawianie elementów do kolejki
    cout << "Inserting elements into the priority queue." << endl;
    pqHeap.insert(10, 10);  // Element 10 z priorytetem 10
    pqHeap.insert(1, 4);    // Element 1 z priorytetem 4
    pqHeap.insert(2, 5);    // Element 2 z priorytetem 5
    pqHeap.insert(20, 15);  // Element 20 z priorytetem 15


    return 0;
}


