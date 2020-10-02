#ifndef PERMUTATIONS
#define PERMUTATIONS

#include <iostream>
#include <vector>
#include <map>
#include "debug.h"
#include "increase_carry.h"

using namespace std;

template <typename T>
class dic_order{
private:
    increase_carry *media_num;
    vector<T> ordered_element;

public:
    dic_order() = delete;
    dic_order(vector<T> init_per);

    void reset();
    bool next_one();
    bool pre_one();
    bool next_n(int n);
    bool pre_n(int n);
    vector<T> get_permutation();
    vector<int> get_media_num();
};

#endif