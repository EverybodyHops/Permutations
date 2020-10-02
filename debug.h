//#define DEBUG

#ifndef DEBUGH
#define DEBUGH
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print_vector(vector<T> a, bool if_reverse=false){
    if(if_reverse){
        reverse(a.begin(), a.end());
    }
    for(auto x: a){
        cout << x << " ";
    }
    cout << endl;
}

#endif