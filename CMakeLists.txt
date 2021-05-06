cmake_minimum_required(VERSION 3.19)
project(DA)

set(CMAKE_CXX_STANDARD 14)

include_directories(Data_Structure)
include_directories(Other_Algorithms)
include_directories(Sort_Algorithms)

add_executable(DA
        Sort_Algorithms/bubble_sort.hpp
        Sort_Algorithms/heap_sort.hpp
        Sort_Algorithms/insertion_sort.hpp
        Sort_Algorithms/merge_sort.hpp
        Sort_Algorithms/quick_sort.hpp
        Sort_Algorithms/selection_sort.hpp
        Sort_Algorithms/shell_sort.hpp
        Other_Algorithms/kmp.hpp
        test.cpp)
