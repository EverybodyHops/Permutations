#include "debug.h"
#include "media_number.h"
#include "permutations.hpp"
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

class magic_square{
public:
    int add(vector<int> p, int begin, int num){
        int ret = 0;
        for(int i = 0; i < num; i++){
            ret += p[begin + i];
        }
        return ret;
    }

    bool if_magic_square(vector<int> p, int rank, int magic_sum){
        int **array2D = new int *[rank];
        for(int i = 0; i < rank; i++){
            array2D[i] = new int[rank];
        }

        for(int i = 0; i < rank; i++){
            for(int j = 0; j < rank; j++){
                array2D[i][j] = p[i * rank + j];
            }
        }
        
        bool flag = true;
        int t1, t2, t3, t4;
        t3 = 0; t4 = 0;
        for(int i = 0; i < rank; i++){
            t1 = 0; t2 = 0;
            for(int j = 0; j < rank; j++){
                t1 += array2D[i][j];
                t2 += array2D[j][i];
            }
            if(t1 != magic_sum || t2 != magic_sum){
                flag = false;
                break;
            }
            t3 += array2D[i][i];
            t4 += array2D[rank - i - 1][i];
        }
        if(t3 != magic_sum || t4 != magic_sum){
            flag = false;
        }

        for(int i = 0; i < rank; i++){
            delete[] array2D[i];
        }
        delete[] array2D;
        return flag;
    }

    vector<vector<int>> get_magic_square(int rank){
        int rank_2;
        rank_2 = rank * rank;

        // initialize
        vector<int> p;
        for(int i = 0; i < rank_2; i++){
            p.push_back(i + 1);
        }
        int k = 0;
        int magic_sum = rank * (rank_2 + 1) / 2;

        // start algorithm
        vector<vector<int>> ans;
        dic_order<int> *dop;
        bool flag = true;
        while(flag){
            if(add(p, k, rank) == magic_sum){
                k += rank;
                if(k == rank_2){
                    k = 0;
                    if(if_magic_square(p, rank, magic_sum)){
                        ans.push_back(p);
                    }
                    dop = new dic_order<int>(p);
                    flag = dop->next_one();
                    p = dop->get_permutation();
                    delete dop;
                }
            }else{
                sort(p.begin() + k + rank, p.end(), greater<int>());
                dop = new dic_order<int>(p);
                flag = dop->next_one();
                p = dop->get_permutation();
                delete dop;
            }
        }
        return ans;
    }

    void print_magic_square(vector<int> p, int rank){
        for(int i = 0; i < rank; i++){
            for(int j = 0; j < rank; j++){
                cout << p[i * rank + j] << " ";
            }
            cout << endl;
        }
    }

    void print_ans(vector<vector<int>> ans, int rank){
        cout << "find " << ans.size() << " magic square!" << endl;
        for(auto p: ans){
            cout << "**********" << endl;
            print_magic_square(p, rank);
        }
    }
};


int main(){
    int rank;
    cout << "input the rank of magic square: ";
    cin >> rank;
    magic_square ms;
    auto ans = ms.get_magic_square(rank);
    ms.print_ans(ans, rank);
}