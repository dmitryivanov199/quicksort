#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

enum class pivot_index_type {
    FIRST,
    LAST,
    RANDOM
};

void quicksort(int *a, unsigned int n, pivot_index_type type);

#endif //QUICKSORT_HPP
