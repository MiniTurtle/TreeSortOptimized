#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <string>

#include "TreeSortOptimized.hpp"
#include "TreeSort.hpp"

int main() {
    const size_t SIZE = 100000;
    const size_t sort_times = 100;
    std::vector<int> sort_this_times[sort_times];
    for (size_t i = 0; i < sort_times; i++) {
        std::vector<int>& sort_this = sort_this_times[i];
        sort_this.resize(SIZE);
        for (auto it = sort_this.begin(); it != sort_this.end(); it++)
            *it = rand();
    }


    //
    // std::sort
    std::vector<int> sort_mem[sort_times];
    for (size_t i = 0; i < sort_times; i++) 
        sort_mem[i] = sort_this_times[i];
    auto t1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < sort_times; i++) 
        std::sort(sort_mem[i].begin(), sort_mem[i].end());
    auto t2 = std::chrono::high_resolution_clock::now();
    
    //
    // Tree sort optimized
    for (size_t i = 0; i < sort_times; i++) 
        sort_mem[i] = sort_this_times[i];
    auto obt1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < sort_times; i++) { 
        treesort_optimized(sort_mem[i]);
    }
    auto obt2 = std::chrono::high_resolution_clock::now(); 
    
    //
    // Tree sort
    for (size_t i = 0; i < sort_times; i++) 
        sort_mem[i] = sort_this_times[i];
    auto bt1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < sort_times; i++)
        treeSort(sort_mem[i]);
    auto bt2 = std::chrono::high_resolution_clock::now();

    std::vector<int> sorted = sort_this_times[0];
    std::sort(sorted.begin(), sorted.end());
    std::vector<int> tree_sorted = sort_this_times[0];
    treesort_optimized(tree_sorted);
     for (size_t i = 0; i < sorted.size(); i++) {
        if (sorted[i] != tree_sorted[i]) {
            std::cout << "Mismatch found!" << std::endl;
            break;
        }
    }

    std::cout << "Sorted time: " << std::chrono::duration<double, std::milli>(t2 - t1).count() << " ms" << std::endl;
    std::cout << "Tree sort time: " << std::chrono::duration<double, std::milli>(bt2 - bt1).count() << " ms" << std::endl;
    std::cout << "Tree sort optimized time: " << std::chrono::duration<double, std::milli>(obt2 - obt1).count() << " ms" << std::endl;

    return 0;
}
