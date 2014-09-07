#include "../lib/quick_sort.h"

#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    unsigned SIZE = 1000;
    QuickSort my_list;

    for (unsigned i = 0; i < SIZE; i++)
        my_list.AddElement(rand());
    my_list.ToScreen();
    my_list.Sort();
    my_list.ToScreen();
    return 0;
}