#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 * 和Single Number类似，只不过这里是数字出现三次，只有一个数字出现一次，那么就没办法用异或来做了．
 * 基于排序和map的方法这里就不说了，思想都和Single Number基本一样．这里谈一谈另外一种算法
 * 用一个sizeof(int) * 8大小的数组来存放一个int数的每一位1出现的次数，如果出现三次就清0，最后将这个数字转换为十进制即可
 *
 *
 *
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    }
};

int main()
{

}
