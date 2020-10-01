#include "debug.h"
#include "increase_carry.h"
#include <iostream>

using namespace std;

int main(){
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
    ic.print_num();
    while(ic.pre()){
        ic.print_num();
        k += 1;
    }
    cout << k << endl;
}