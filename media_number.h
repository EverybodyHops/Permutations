#ifndef INCREASE_CARRY
#define INCREASE_CARRY

#include <vector>
#include <iostream>
#include "debug.h"

using namespace std;

class media_number{
    //num[0] is lowest
    //num[digit - 1] is highest
    //num[digit] is flag of overflow and underflow
protected:
    vector<int> num, carry;
public:
    vector<int> get_num();
    vector<int> get_carry();
    void print_num();
    void print_carry();
    void reset();

    vector<int> dec2media(int dec);
    bool if_vector_legal(vector<int> v);
    bool add_vector(vector<int> v);
    bool sub_vector(vector<int> v);
    bool add_dec(int dec);
    bool sub_dec(int dec);
    bool next();
    bool pre();
};


class increase_carry: public media_number{
public:
    increase_carry() = delete;
    increase_carry(int digit);
    increase_carry(vector<int> _num);
};

class decrease_carry: public media_number{
public:
    decrease_carry() = delete;
    decrease_carry(int digit);
    decrease_carry(vector<int> _num);
};

#endif