#include "debug.h"
#include "media_number.h"
#include "permutations.hpp"
#include <iostream>

using namespace std;

int main(){
    vector<int> now_per = {8,3,6,7,4,5,2,1};
    dic_order<int> a(now_per);
    //print_vector<int>(a.get_media_num(), true);
    a.pre_n(2020);
    //print_vector<int>(a.get_media_num(), true);
    print_vector<int>(a.get_permutation());

    increase_carry_order<int> b(now_per);
    //print_vector<int>(b.get_media_num(), true);
    //print_vector<int>(b.get_permutation());
    b.pre_n(2020);
    //print_vector<int>(b.get_media_num(), true);
    print_vector<int>(b.get_permutation());

    vector<char> cp = {'a','b', 'c', 'd'};
    dic_order<char> c(cp);
    int t = 1;
    while(c.next_one())
    {
        //print_vector<int>(c.get_media_num(), true);
        print_vector<char>(c.get_permutation());
        t += 1;
    }
    cout << t;
}