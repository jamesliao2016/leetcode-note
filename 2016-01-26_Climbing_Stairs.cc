#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*  DP解法,递归实现，也可以迭代解决这个问题，还可以递归
 *  递归解法会超时
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 or n == 2)
            return n;
        else return climbStairs(n -1) + climbStairs(n - 2);
    }
};

/*
 *  迭代求解
 *
 *
 */
class Solution2 {
public:
    int climbStairs(int n) {
        int data[n + 1];  //用于迭代求解
        //初始化迭代的基础解
        data[1] = 1;
        data[2] = 2;

        for(int i = 3; i <= n; i++) {
                data[i] = data[i -1] + data[i - 2];
        }
        return data[n];

    }
};


int main()
{
    Solution2 so2;
    Solution so;
    cout << so.climbStairs(10) << endl;
    cout << so2.climbStairs(10);
}
