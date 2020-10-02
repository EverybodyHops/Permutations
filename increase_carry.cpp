#include "increase_carry.h"

using namespace std;

increase_carry::increase_carry(int digit){
    for(int i = 0; i <= digit; i++){
        num.push_back(0);
    }
}

increase_carry::increase_carry(vector<int> _num){
    num.assign(_num.begin(), _num.end());
    num.push_back(0);
    #ifdef DEBUG
        cout << "Init by vector." << endl;
        print_num();
    #endif
}

vector<int> increase_carry::get_num(){
    vector<int> res = num;
    res.pop_back();
    return res;
}

void increase_carry::print_num(){
    cout << "now num: ";
    for(int i = num.size() - 1; i >= 0; i--){
        cout << num[i] << " ";
    }
    cout << endl;
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
            print_num();
        #endif
        pre();
        #ifdef DEBUG
            cout << "After handle overflow." << endl;
            print_num();
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
            print_num();
        #endif
        next();
        #ifdef DEBUG
            cout << "After handle unferflow." << endl;
            print_num();
        #endif
        return false;
    }
}

bool increase_carry::add_vector(vector<int> v){
    if(v.size() >= num.size()){
        return false;
    }

    for(int i = 0; i < num.size() - 1; i++){
        if(i < v.size()){  
            num[i] += v[i];
        }
        if(num[i] >= i + 2){
            num[i] -= i + 2;
            num[i + 1] += 1;
        }
    }

    if(num[num.size() - 1] > 0){
        #ifdef DEBUG
            cout << "Overflow!" << endl;
            print_num();
        #endif
        sub_vector(v);
        #ifdef DEBUG
            cout << "After handle overflow." << endl;
            print_num();
        #endif
        return false;
    }
}

bool increase_carry::add_dec(int dec){
    return add_vector(dec2increase(dec));
}

bool increase_carry::sub_vector(vector<int> v){
    if(v.size() >= num.size()){
        return false;
    }

    for(int i = 0; i < num.size() - 1; i++){
        if(i < v.size()){  
            num[i] -= v[i];
        }
        if(num[i] < 0){
            num[i] += i + 2;
            num[i + 1] -= 1;
        }
    }

    if(num[num.size() - 1] > 0){
        #ifdef DEBUG
            cout << "Underflow!" << endl;
            print_num();
        #endif
        add_vector(v);
        #ifdef DEBUG
            cout << "After handle unferflow." << endl;
            print_num();
        #endif
        return false;
    }
}

bool increase_carry::sub_dec(int dec){
    return sub_vector(dec2increase(dec));
}