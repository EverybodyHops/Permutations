#include "debug.h"
#include "media_number.h"
#include "permutations.hpp"
#include <iostream>

using namespace std;

int main(){
    vector<int> now_per = {8,3,6,7,4,5,2,1};
    dic_order<int> a(now_per);
    a.print_media_carry();
    a.pre_n(2020);
    a.print_media_num();
    print_vector<int>(a.get_permutation());
    a.next_n(2020);
    a.print_media_num();
    print_vector<int>(a.get_permutation());

    increase_carry_order<int> b(now_per);
    b.print_media_carry();
    b.pre_n(2020);
    b.print_media_num();
    print_vector<int>(b.get_permutation());
    b.next_n(2020);
    b.print_media_num();
    print_vector<int>(b.get_permutation());

    decrease_carry_order<int> c(now_per);
    c.print_media_carry();
    c.pre_n(2020);
    c.print_media_num();
    print_vector<int>(c.get_permutation());
    c.next_n(2020);
    c.print_media_num();
    print_vector<int>(c.get_permutation());

    /*
    vector<char> cp = {'a','b', 'c'};
    dic_order<char> c(cp);
    int t = 1;
    while(c.next_one())
    {
        c.print_media_num();
        print_vector<char>(c.get_permutation());
        t += 1;
    }
    cout << t << endl;
    */
}