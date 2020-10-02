#include "permutations.h"

template <typename T>
dic_order<T>::dic_order(vector<T> init_per){
    ordered_element = init_per;
    sort(ordered_element.begin(), ordered_element.end());

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
    media_num = new increase_carry(t);

    #ifdef DEBUG
        media_num->print_num();
    #endif
}

template <typename T>
void dic_order<T>::reset(){
    int len = media_num->get_num().size();
    delete media_num;
    media_num = new increase_carry(len);
}

template <typename T>
bool dic_order<T>::next_one(){
    return media_num->next();
}

template <typename T>
bool dic_order<T>::pre_one(){
    return media_num->pre();
}

template <typename T>
bool dic_order<T>::next_n(int n){
    return media_num->add_dec(n);
}

template <typename T>
bool dic_order<T>::pre_n(int n){
    return media_num->sub_dec(n);
}

template <typename T>
vector<T> dic_order<T>::get_permutation(){
    int len = ordered_element.size();
    bool *can_use = new bool[len];
    for(int i = 0; i < ordered_element.size(); i++){
        can_use[i] = true;
    }

    vector<int> m_num = media_num->get_num();
    vector<T> res;
    int temp;
    for(int i = m_num.size() - 1; i >= 0; i--){
        temp = m_num[i];
        for(int j = 0; j < len; j++){
            if(can_use[j]){
                if(temp == 0){
                    res.push_back(ordered_element[j]);
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
            res.push_back(ordered_element[i]);
            break;
        }
    }
    return res;
}

template <typename T>
vector<int> dic_order<T>::get_media_num(){
    return media_num->get_num();
}