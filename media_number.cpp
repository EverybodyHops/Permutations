#include "media_number.h"

using namespace std;

vector<int> media_number::get_num(){
    vector<int> res = num;
    res.pop_back();
    return res;
}

vector<int> media_number::get_carry(){
    vector<int> res = carry;
    return res;
}

void media_number::print_num(){
    cout << "now num: ";
    for(int i = num.size() - 1; i >= 0; i--){
        cout << num[i] << " ";
    }
    cout << endl;
}

void media_number::print_carry(){
    cout << "now carry: ";
    for(int i = carry.size() - 1; i >= 0; i--){
        cout << carry[i] << " ";
    }
    cout << endl;
}

void media_number::reset(){
    for(int i = 0; i < num.size(); i++){
        num[i] = 0;
    }
}

vector<int> media_number::dec2media(int dec){
    vector<int> res;
    int t = 0;
    while(dec > 0){
        if(t == carry.size()){
            res.push_back(dec);
        }
        res.push_back(dec % carry[t]);
        dec /= carry[t++];
    }
    return res;
}

bool media_number::if_vector_legal(vector<int> v){
    if(v.size() > carry.size()){
        #ifdef DEBUG
            cout << "Vector illegal (too long)!" << endl;
            print_vector<int>(v);
        #endif
        return false;
    }
    for(int i = 0; i < v.size(); i++){
        if(v[i] >= carry[i]){
            #ifdef DEBUG
                cout << "Vector illegal (bigger than carry)!" << endl;
                print_vector<int>(v);
            #endif
            return false;
        }
    }
    return true;
}

bool media_number::add_vector(vector<int> v){
    if(!if_vector_legal(v)){
        return false;
    }

    for(int i = 0; i < num.size() - 1; i++){
        if(i < v.size()){  
            num[i] += v[i];
        }
        if(num[i] >= carry[i]){
            num[i] -= carry[i];
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
    return true;
}

bool media_number::sub_vector(vector<int> v){
    if(!if_vector_legal(v)){
        return false;
    }

    for(int i = 0; i < num.size() - 1; i++){
        if(i < v.size()){  
            num[i] -= v[i];
        }
        if(num[i] < 0){
            num[i] += carry[i];
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

    return true;
}

bool media_number::add_dec(int dec){
    return add_vector(dec2media(dec));
}

bool media_number::sub_dec(int dec){
    return sub_vector(dec2media(dec));
}

bool media_number::next(){
    return add_dec(1);
}

bool media_number::pre(){
    return sub_dec(1);
}

increase_carry::increase_carry(int digit){
    for(int i = 0; i < digit; i++){
        num.push_back(0);
        carry.push_back(i + 2);
    }
    num.push_back(0);
}

increase_carry::increase_carry(vector<int> _num){
    num.assign(_num.begin(), _num.end());
    for(int i = 0; i < num.size(); i++){
        carry.push_back(i + 2);
    }
    num.push_back(0);
}

decrease_carry::decrease_carry(int digit){
    for(int i = 0; i < digit; i++){
        num.push_back(0);
        carry.push_back(digit + 1 - i);
    }
    num.push_back(0);
}

decrease_carry::decrease_carry(vector<int> _num){
    num.assign(_num.begin(), _num.end());
    for(int i = 0; i < num.size(); i++){
        carry.push_back(num.size() - i + 1);
    }
    num.push_back(0);
}