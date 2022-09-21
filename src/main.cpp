#include <iostream>

#include "quicksort.hpp"

bool run_tests();

unsigned int get_random_array_number();

void fill_array(int *a, unsigned int n);

void copy_array(int *dst, const int *src, unsigned int n);

int compare_numbers(const void *a, const void *b);

bool compare_arrays(const int *a, const int *b, unsigned int n);

int main() {
    if (run_tests()) {
        std::cout << "All tests passed successfully!" << std::endl;
    }
    else {
        std::cout << "Something went wrong..." << std::endl;
    }
    
    return 0;
}

bool run_tests() {
    const unsigned int tests_number{10000};

    for (unsigned int i{0}; i < tests_number; i++) {
        const unsigned int n{get_random_array_number()};
        int source_a[n];
        fill_array(source_a, n);

        int std_sorted_a[n];
        copy_array(std_sorted_a, source_a, n);
        std::qsort(std_sorted_a, n, sizeof(int), compare_numbers);

        int my_sorted_a_first[n];
        copy_array(my_sorted_a_first, source_a, n);
        quicksort(my_sorted_a_first, n, pivot_index_type::FIRST);

        int my_sorted_a_last[n];
        copy_array(my_sorted_a_last, source_a, n);
        quicksort(my_sorted_a_last, n, pivot_index_type::LAST);

        int my_sorted_a_random[n];
        copy_array(my_sorted_a_random, source_a, n);
        quicksort(my_sorted_a_random, n, pivot_index_type::RANDOM);

        int my_sorted_a_median[n];
        copy_array(my_sorted_a_median, source_a, n);
        quicksort(my_sorted_a_median, n, pivot_index_type::MEDIAN);

        if (!compare_arrays(my_sorted_a_first, std_sorted_a, n) ||
            !compare_arrays(my_sorted_a_last, std_sorted_a, n) ||
            !compare_arrays(my_sorted_a_random, std_sorted_a, n) ||
            !compare_arrays(my_sorted_a_median, std_sorted_a, n)) {
            return false;
        }
    }

    return true;
}

unsigned int get_random_array_number() {
    const unsigned int min{1};
    const unsigned int max{1000};
    std::srand(time(0));
    return min + std::rand() % (max - min + 1);
}

void fill_array(int *a, unsigned int n) {
    std::srand(time(0));

    for (unsigned int i{0}; i < n; i++) {
        a[i] = std::rand();
    }
}

void copy_array(int *dst, const int *src, unsigned int n) {
    for (unsigned int i{0}; i < n; i++) {
        dst[i] = src[i];
    }
}

int compare_numbers(const void *a, const void *b) {
    const int arg1{*static_cast<const int*>(a)};
    const int arg2{*static_cast<const int*>(b)};
    return arg1 > arg2;
}

bool compare_arrays(const int *a, const int *b, unsigned int n) {
    for (unsigned int i{0}; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}
