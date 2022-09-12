#include <iostream>

#include "quicksort.hpp"

static void make_quick_sorting(int *a, unsigned int l, unsigned int r, pivot_index_type pivot_type);

static bool is_base_case(unsigned int l, unsigned int r);

static unsigned int choose_pivot_index(const int *a, unsigned int l, unsigned int r, pivot_index_type pivot_type);

static unsigned int get_median_index(const int *a, unsigned int l, unsigned int r);

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
    
    unsigned int i{choose_pivot_index(a, l, r, pivot_type)};
    swap_elements(a[l], a[i]);

    unsigned int j{make_partition(a, l, r)};

    if (static_cast<int>(j - 1) < 0) {
        make_quick_sorting(a, l, 0, pivot_type);
        make_quick_sorting(a, 1, r, pivot_type);
    }
    else {
        make_quick_sorting(a, l, j - 1, pivot_type);
        make_quick_sorting(a, j + 1, r, pivot_type);
    }
}

bool is_base_case(unsigned int l, unsigned int r) {
    return l >= r;
}

unsigned int choose_pivot_index(const int *a, unsigned int l, unsigned int r, pivot_index_type pivot_type) {
    switch (pivot_type) {
    case pivot_index_type::FIRST:
        return l;

    case pivot_index_type::LAST:
        return r;
    
    case pivot_index_type::RANDOM:
        srand(time(0));
        return l + rand() % (r - l + 1);

    default:
        return get_median_index(a, l, r);
    }
}

unsigned int get_median_index(const int *a, unsigned int l, unsigned int r) {
    const unsigned int middle_index{(r - l) / 2};
    int sample[3]{a[l], a[middle_index], a[r]};
    quicksort(sample, 3, pivot_index_type::FIRST);

    if (sample[1] == a[l]) {
        return l;
    }
    else if (sample[1] == a[middle_index]) {
        return middle_index;
    }
    else {
        return r;
    }
}

void swap_elements(int &a, int &b) {
    int temp{a};
    a = b;
    b = temp;
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
