#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 *  这题还是很简单的，给定一个数组找到只出现一次的那个数，方法很多
 *  方法1: 使用一个map记录出现的次数，先扫描一遍记录数字出现的次数，然后扫描一遍map找到只出现一次的那个数．空间复杂度高
 *  方法2: 排序然后相邻元素比较，时间复杂度高
 *  方法3: 异或，因为题目说了，每个数字都出现二次，只有一个数字是只出现一次的，因此只要相互异或即可，例如
 *  1 2 1 2 3
 *  1 先和 2异或，然后再和1异或，结果就是2，然后再和2异或是0，最后0和3异或还是3
 *
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret  = 0;
        for(auto num : nums) {
            ret = ret ^ num;
        }
        return ret;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

int main()
{

}
