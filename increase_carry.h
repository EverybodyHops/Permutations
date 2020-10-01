#ifndef INCREASE_CARRY
#define INCREASE_CARRT

#include <vector>

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
    bool next();
    bool pre();
    vector<int> get_num();
    void print_num();
};

#endif