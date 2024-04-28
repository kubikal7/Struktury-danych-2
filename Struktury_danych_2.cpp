#include <iostream>
#include "ArrayList.h"
#include "PQAL_element.h"
#include "PriorityQueueArrayList.h"
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
}

