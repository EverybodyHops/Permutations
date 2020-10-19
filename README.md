# 全排列生成算法及其应用

清华大学（THU）2020秋组合数学 课程项目  
<br/> 

# 项目说明  

本项目代码由朱子睿（2020310798）完成，代码仅供参考交流，若用于其他用途请与作者沟通。  
<br/> 

# 使用说明

## 全排列生成算法

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

## 利用全排列构造幻方

参考文献为：
```
林淑飞. 改进全排列算法构造任意阶幻方[J]. 数字技术与应用, 2013, 000(008):116-117.
```

项目的`magic_square.cpp`文件中的`magic_square`类复现了文献中提出的算法，并实现了如下接口：

* `vector<vector<int>> get_magic_square(int rank)`： 返回所有的`rank`阶幻方的一维表示（将幻方按照从左到右，从上到下的顺序写成一个向量）。
* `void print_ans(vector<vector<int>> ans, int rank)`: 格式化打印前一接口的返回值。
* `void print_magic_square(vector<int> p, int rank)`：打印一个幻方的对应向量。
* `bool if_magic_square(vector<int> p, int rank, int magic_sum)`：判断一个向量是否为幻方。

注：由于前面设计的全排列生成算法主要目的在于快速生成一系列中介数相邻的排列，和文献中设计的算法对全排列生成算法的需求不同（文献中要求的是快速生成某一排列的字典序对应的下一个排列）。因此在1到3阶的场景下可以在可接受的时间内完成计算，4阶及以上的情况所需时间较长，特此说明。