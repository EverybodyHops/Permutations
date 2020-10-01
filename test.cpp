#include "debug.h"
#include "increase_carry.h"
#include <iostream>

using namespace std;

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(4);
    a.push_back(4);
    a.push_back(7);
    increase_carry test(a);
    
    for(int i = 0; i < 2020; i++){
        test.pre();
    }
    test.print_num();

    auto b = test.dec2increase(2020);
    print_vector<int>(b, true);
    print_vector<int>(b);
    /*
    int k = 0;
    increase_carry ic(4);
    ic.print_num();
    while(ic.next()){
        ic.print_num();
        k += 1;
    }
    cout << k << endl;
    
    k = 0;
    auto t = ic.get_num();
    increase_carry ic2(t);
    ic2.print_num();
    while(ic2.pre()){
        ic2.print_num();
        k += 1;
    }
    cout << k << endl;
    */
}