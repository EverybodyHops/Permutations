# 全排列生成算法  

清华大学（THU）2020秋组合数学 课程项目  
<br/> 

# 项目说明  

本项目代码由朱子睿（2020310798）完成，代码仅供参考交流，若用于其他用途请与作者沟通。  
<br/> 

# 使用说明

使用前需要将代码文件复制到你的工程目录下，然后：
```c++
#include "permutations.hpp"
```  

本项目实现了四种全排列生成算法： 
* dic_order： 字典序法
* increase_carry_order：递增进位制数法
* decrease_carry_order：递减进位制数法
* ortho_transposition： 邻位对换法

下面以字典序法为例介绍如何使用：
* 初始化
```c++
vector<int> now_per = {8,3,6,7,4,5,2,1};
dic_order<int> a(now_per);
```
使用某一个排列初始化（将当前中介数设置为该排列对应中介数）。

* 接口
    * `void reset()`：使中介数归零。
    * `bool next_one()`：使中介数加一，返回是否成功。
    * `bool pre_one()`：使中介数减一，返回是否成功。
    * `bool next_n(int n)`：使中介数加n，返回是否成功。
    * `bool pre_n(int n)`：使中介数减n，返回是否成功。
    * `vector<int> get_media_num()`：返回当前中介数，v[0]为最低位。
    * `void print_media_num()`：打印当前中位数。
    * `vector<T> get_permutation()`：返回当前中介数对应的排列。

具体使用见`test.cpp`。