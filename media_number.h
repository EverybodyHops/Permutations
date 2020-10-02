#ifndef INCREASE_CARRY
#define INCREASE_CARRY

#include <vector>
#include <iostream>
#include "debug.h"

using namespace std;

class media_number{
protected:
    vector<int> num;
public:
    vector<int> get_num();
    void reset();
    void print_num();

    virtual vector<int> dec2media(int dec) = 0;
    virtual bool next() = 0;
    virtual bool pre() = 0;
    virtual bool add_vector(vector<int> v) = 0;
    virtual bool add_dec(int dec) = 0;
    virtual bool sub_vector(vector<int> v) = 0;
    virtual bool sub_dec(int dec) = 0;
};


class increase_carry: public media_number{
    //num[0] is lowest
    //num[digit - 1] is highest
    //num[digit] is flag of overflow
public:
    increase_carry() = delete;
    increase_carry(int digit);
    increase_carry(vector<int> _num);

    vector<int> dec2media(int dec) override;
    bool next() override;
    bool pre() override;
    bool add_vector(vector<int> v) override;
    bool add_dec(int dec) override;
    bool sub_vector(vector<int> v) override;
    bool sub_dec(int dec) override;
};

#endif