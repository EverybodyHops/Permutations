#include "debug.h"
#include "media_number.h"
#include "permutations.hpp"
#include <iostream>

using namespace std;

int main(){
    vector<int> now = {1,2,2,2,4,4,7};
    media_number *t = new increase_carry(now);
    t->sub_dec(2020);
    t->print_num();

    vector<int> now_per = {8,3,6,7,4,5,2,1};
    dic_order<int> a(now_per);
    print_vector<int>(a.get_media_num());
    a.pre_n(2020);
    print_vector<int>(a.get_media_num());
    print_vector<int>(a.get_permutation());
}