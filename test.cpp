#include "debug.h"
#include "media_number.h"
#include "permutations.hpp"
#include <iostream>

using namespace std;

int main(){
    vector<int> now_per = {8,3,6,7,4,5,2,1};
    //vector<int> now_per = {1,2,3,4,5,6,7,8};
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

    ortho_transposition<int> d(now_per);
    d.print_media_carry();
    d.pre_n(2020);
    d.print_media_num();
    print_vector<int>(d.get_permutation());
    d.next_n(2020);
    d.print_media_num();
    print_vector<int>(d.get_permutation());
    
    vector<char> cp = {'a', 'b', 'c', 'd'};
    ortho_transposition<char> e(cp);
    print_vector<char>(e.get_permutation());
    int t = 1;
    while(e.next_one())
    {
        //e.print_media_num();
        print_vector<char>(e.get_permutation());
        t += 1;
    }
    cout << t << endl;
}