#ifndef INCREASE_CARRY
#define INCREASE_CARRY

#include <vector>
#include <iostream>
#include "debug.h"

using namespace std;

class increase_carry{
    //num[0] is lowest
    //num[digit - 1] is highest
    //num[digit] is flag of overflow
private:
    vector<int> num;
public:
    increase_carry() = delete;
    increase_carry(int digit);
    increase_carry(vector<int> _num);

    vector<int> get_num();
    void print_num();
    vector<int> dec2increase(int dec);

    bool next();
    bool pre();
    bool add_vector(vector<int> v);
    bool add_dec(int dec);
    bool sub_vector(vector<int> v);
    bool sub_dec(int dec);
};

#endif