#include <iostream>

#include "quicksort.hpp"

static void make_quick_sorting(int *a, unsigned int l, unsigned int r, pivot_index_type pivot_type);

static bool is_base_case(unsigned int l, unsigned int r);

static unsigned int choose_pivot_index(pivot_index_type pivot_type, unsigned int l, unsigned int r);

static void swap_elements(int &a, int &b);

static unsigned int make_partition(int *a, unsigned int l, unsigned int r);

//----------------------------------------------------------------------------

void quicksort(int *a, unsigned int n, pivot_index_type pivot_type) {
    make_quick_sorting(a, 0, n - 1, pivot_type);
}

//----------------------------------------------------------------------------

void make_quick_sorting(int *a, unsigned int l, unsigned int r, pivot_index_type pivot_type) {
    if (is_base_case(l, r)) {
        return;
    }
    
    unsigned int i{choose_pivot_index(pivot_type, l, r)};
    swap_elements(a[l], a[i]);
    unsigned int j{make_partition(a, l, r)};
    make_quick_sorting(a, l, j - 1, pivot_type);
    make_quick_sorting(a, j + 1, r, pivot_type);
}

bool is_base_case(unsigned int l, unsigned int r) {
    return l >= r;
}

unsigned int choose_pivot_index(pivot_index_type pivot_type, unsigned int l, unsigned int r) {
    switch (pivot_type) {
    case pivot_index_type::FIRST:
        return l;

    case pivot_index_type::LAST:
        return r;
    
    default:
        return rand() % r + l;
    }
}

void swap_elements(int &a, int &b) {
    a += b;
    b = a - b;
    a -= b;
}

unsigned int make_partition(int *a, unsigned int l, unsigned int r) {
    int p{a[l]};
    unsigned int i{l + 1};

    for (unsigned int j{l + 1}; j <= r; j++) {
        if (a[j] < p) {
            swap_elements(a[i], a[j]);
            i++;
        }
    }

    swap_elements(a[l], a[i - 1]);
    return i - 1;
}
