#include "increase_carry.h"
#include <iostream>

using namespace std;

increase_carry::increase_carry(int digit){
    for(int i = 0; i <= digit; i++){
        this->num.push_back(0);
    }
}

increase_carry::increase_carry(vector<int> _num){
    this->num.assign(_num.begin(), _num.end());
    #ifdef DEBUG
        cout << "Init by vector." << endl;
        this->print_num();
    #endif
    this->num.push_back(0);
}

bool increase_carry::next(){
    num[0] += 1;
    for(int i = 0; i < num.size() - 1; i++){
        if(num[i] == i + 2){
            num[i] = 0;
            num[i + 1] += 1;
        }else{
            return true;
        }
    }
    if(num[num.size() - 1] > 0){
        #ifdef DEBUG
            cout << "Overflow!" << endl;
            this->print_num();
        #endif
        this->pre();
        #ifdef DEBUG
            cout << "After handle overflow." << endl;
            this->print_num();
        #endif
        return false;
    }
}

bool increase_carry::pre(){
    num[0] -= 1;
    for(int i = 0; i < num.size() - 1; i++){
        if(num[i] == -1){
            num[i] = i + 1;
            num[i + 1] -= 1;
        }else{
            return true;
        }
    }
    if(num[num.size() - 1] < 0){
        #ifdef DEBUG
            cout << "Underflow!" << endl;
            this->print_num();
        #endif
        this->next();
        #ifdef DEBUG
            cout << "After handle unferflow." << endl;
            this->print_num();
        #endif
        return false;
    }
}

void increase_carry::print_num(){
    cout << "now num: ";
    for(int i = num.size() - 1; i >= 0; i--){
        cout << num[i] << " ";
    }
    cout << endl;
}

vector<int> increase_carry::get_num(){
    vector<int> res = this->num;
    res.pop_back();
    return res;
}

vector<int> increase_carry::dec2increase(int dec){
    vector<int> res;
    int t = 2;
    while(dec > 0){
        res.push_back(dec % t);
        dec /= t++;
    }
    return res;
}