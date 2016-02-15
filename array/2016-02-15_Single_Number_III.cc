#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


/*
 *  Single number I
 *  Single number II
 *  Single number III 这三类题目都是属于位操作
 *  本题的基本思路还是异或操作来消除出现两次的数.基本步骤如下:
 *  Setp1: 通过异或操作消除出现两次的数,最后只剩下两个不同数的异或结果 设为A ^ B (A和B是两个只出现一次的数)
 *  Setp2: 每次和对应数的平方求异或,最后得到的结果就是A^2 ^ B^2(A和B同上)
 *  Setp3: 再次遍历数组,取出每个数和Setp1的结果想异或,如果取出的数是A,那么异或的结果是B
 *         然后拿B^2和Setp2的结果异或得到A^2,最后验证结果是否等于取出的数的平方
 *
 *
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0,y = 0,tmp;
        vector<int> ans;
        for(int n : nums) {
            x ^= n;
            y ^= (n * n);
        }

        for(int n : nums) {
            tmp = n ^ x;
            if(((tmp * tmp) ^y) == n * n) ans.push_back(n);
        }
        return ans;
    }
};


int main()
{

}
