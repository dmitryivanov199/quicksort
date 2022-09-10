#include <iostream>

#include "quicksort.hpp"

static void make_quick_sorting(int *a, unsigned int n, unsigned int l, unsigned int r, pivot_index_type pivot_type);

static bool is_base_case(unsigned int l, unsigned int r);

static unsigned int choose_pivot_index(pivot_index_type pivot_type, unsigned int n);

//----------------------------------------------------------------------------

void quicksort(int *a, unsigned int n, pivot_index_type pivot_type) {
    make_quick_sorting(a, n, 0, n - 1, pivot_type);
}

//----------------------------------------------------------------------------

void make_quick_sorting(int *a, unsigned int n, unsigned int l, unsigned int r, pivot_index_type pivot_type) {
    if (is_base_case(l, r)) {
        return;
    }

    unsigned int i{choose_pivot_index(pivot_type, n)};
}

bool is_base_case(unsigned int l, unsigned int r) {
    return l >= r;
}

unsigned int choose_pivot_index(pivot_index_type pivot_type, unsigned int n) {
    switch (pivot_type) {
    case pivot_index_type::FIRST:
        return 0;

    case pivot_index_type::LAST:
        return n - 1;
    
    default:
        return rand() % n;
    }
}
