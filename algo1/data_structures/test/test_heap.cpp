#include "../lib/heap.h"
#include "stdlib.h"
#include "time.h"
#include "iostream"

int main(void){
    srand(time(NULL));
    Heap oneHeap;
    HeapElement elem;
    const unsigned SIZE = 10;
    std::cout << "Input data: ";
    for(unsigned i = 0; i < SIZE; i++){
        elem.key = rand();
        oneHeap.Add(elem);
        std::cout << elem.key << ' ';
    }

    std::cout << "\nOutput data: ";
    for (unsigned i = 0; i< SIZE; i++)
        std::cout << oneHeap.Pop().key << ' ';

}
