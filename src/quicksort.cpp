#include "quicksort.hpp"

static void make_quick_sorting(int *a, unsigned int n, unsigned int l, unsigned int r, pivot_index_type pivot_type);

static bool is_base_case(unsigned int l, unsigned int r);

//----------------------------------------------------------------------------

void quicksort(int *a, unsigned int n, pivot_index_type pivot_type) {
    make_quick_sorting(a, n, 0, n - 1, pivot_type);
}

//----------------------------------------------------------------------------

void make_quick_sorting(int *a, unsigned int n, unsigned int l, unsigned int r, pivot_index_type pivot_type) {
    if (is_base_case(l, r)) {
        return;
    }
}

bool is_base_case(unsigned int l, unsigned int r) {
    return l >= r;
}
