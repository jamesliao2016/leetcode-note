#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 *  刚开始看了半天没看懂，英语太渣了，题目的大致意思就是使用vector来存储一个数字，
 *  数字的高位在vector的最低位，也就是对于数字98来说，0下标上放9，1下标上放8，现在要给这个数+1．
 *
 *  题目还是很easy的，从最低位开始，一次累加，然后进位，直到不再进位，或者进位达到最高位为止．
 *  注: 难点就是进位什么时候结束，如果在0下标处还进位了怎么去处理
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int flag = 0;
        int sum;
        sum = digits[size - 1] + 1;
        digits[size -1] = sum >= 10 ? flag = 1,sum - 10 : sum;

        if(!flag) return digits;

        for(int i = size - 2;i >= 0; --i) {
            sum = digits[i] + flag;
            digits[i] = sum >= 10 ? flag = 1,sum - 10 : flag = 0,sum;
            if(!flag)
                return digits;
        }

        //处理最后一步
        if(flag) {
            digits.insert(digits.begin(),flag);
        }

        return digits;
    }
};

int main()
{
    vector<int> data = {8,9,9,9};
    Solution so;
    vector<int> ret = so.plusOne(data);
    for(auto num : ret)
        cout << num << endl;

}
