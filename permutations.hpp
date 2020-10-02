#ifndef PERMUTATIONS
#define PERMUTATIONS

#include <iostream>
#include <vector>
#include <map>
#include "debug.h"
#include "media_number.h"

using namespace std;

template <typename T>
class permutations{
protected:
    media_number *media_num;
    vector<T> ordered_element;
public:
    ~permutations(){
        #ifdef DEBUG
            cout << "release media_num." << endl;
        #endif
        delete media_num;
    }

    void reset(){
        media_num->reset();
    }

    bool next_one(){
        return media_num->next();
    }

    bool pre_one(){
        return media_num->pre();
    }

    bool next_n(int n){
        return media_num->add_dec(n);
    }

    bool pre_n(int n){
        return media_num->sub_dec(n);
    }

    vector<int> get_media_num(){
        return media_num->get_num();
    }
    
    virtual vector<T> get_permutation() = 0;
};


template <typename T>
class dic_order: public permutations<T>{
public:
    dic_order() = delete;

    dic_order(vector<T> init_per){
        this->ordered_element = init_per;
        sort(this->ordered_element.begin(), this->ordered_element.end());

        //permutation to media number
        vector<int> t;
        int temp;
        for(int i = 0; i < init_per.size() - 1; i++){
            temp = 0;
            for(int j = i + 1; j < init_per.size(); j++){
                if(init_per[i] > init_per[j]){
                    temp += 1;
                }
            }
            t.push_back(temp);
        }
        reverse(t.begin(), t.end());
        this->media_num = new increase_carry(t);

        #ifdef DEBUG
            this->media_num->print_num();
        #endif
    }

    vector<T> get_permutation() override{
        int len = this->ordered_element.size();
        bool *can_use = new bool[len];
        for(int i = 0; i < this->ordered_element.size(); i++){
            can_use[i] = true;
        }

        vector<int> m_num = this->media_num->get_num();
        vector<T> res;
        int temp;
        for(int i = m_num.size() - 1; i >= 0; i--){
            temp = m_num[i];
            for(int j = 0; j < len; j++){
                if(can_use[j]){
                    if(temp == 0){
                        res.push_back(this->ordered_element[j]);
                        can_use[j] = false;
                        break; 
                    }else{
                        temp -= 1;
                    }
                }
            }
        }
        for(int i = 0; i < len; i++){
            if(can_use[i]){
                res.push_back(this->ordered_element[i]);
                break;
            }
        }
        delete[] can_use;
        return res;
    }
};

template <typename T>
class increase_carry_order: public permutations<T>{
public:
    increase_carry_order() = delete;

    increase_carry_order(vector<T> init_per){
        this->ordered_element = init_per;
        sort(this->ordered_element.begin(), this->ordered_element.end());

        //permutation to media number
        vector<int> t;
        int temp;
        for(int i = 1; i < this->ordered_element.size(); i++){
            temp = 0;
            for(int j = init_per.size() - 1; j >= 0; j--){
                if(init_per[j] < this->ordered_element[i]){
                    temp += 1;
                }
                if(init_per[j] == this->ordered_element[i]){
                    break;
                }
            }
            t.push_back(temp);
        }
        this->media_num = new increase_carry(t);

        #ifdef DEBUG
            this->media_num->print_num();
        #endif
    }

    vector<T> get_permutation() override{
        int len = this->ordered_element.size();
        bool *can_put = new bool[len];
        for(int i = 0; i < this->ordered_element.size(); i++){
            can_put[i] = true;
        }

        vector<int> m_num = this->media_num->get_num();
        vector<T> res(len);
        int temp;
        for(int i = m_num.size() - 1; i >= 0; i--){
            temp = m_num[i];
            for(int j = 0; j < len; j++){
                if(can_put[j]){
                    if(temp == 0){
                        res[j] = this->ordered_element[i + 1];
                        can_put[j] = false;
                        break; 
                    }else{
                        temp -= 1;
                    }
                }
            }
        }
        for(int i = 0; i < len; i++){
            if(can_put[i]){
                res[i] = this->ordered_element[0];
                break;
            }
        }
        delete[] can_put;
        reverse(res.begin(), res.end());
        return res;
    }
};
#endif