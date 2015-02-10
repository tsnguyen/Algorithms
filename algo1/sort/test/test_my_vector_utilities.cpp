#include "../lib/my_vector_utilities.h"

#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    unsigned SIZE = 10;

    std::vector<int> vec(SIZE);
    for (unsigned i = 0; i < SIZE; i++)
        vec[i] = rand();

    VectorToScreen(vec);

    std::cout << "The index of the largest element is "
              << IndexOfMaxElement(vec, 0, SIZE) << '\n';
    SwapVectorElements(vec, 1, 2);
    VectorToScreen(vec);
    MergeSort(vec);
    VectorToScreen(vec);
}