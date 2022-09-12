#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

enum class pivot_index_type {
    FIRST,
    LAST,
    RANDOM,
    MEDIAN
};

void quicksort(int *a, unsigned int n, pivot_index_type pivot_type);

#endif //QUICKSORT_HPP
