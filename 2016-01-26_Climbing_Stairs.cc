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

class Solution2 {
public:
    int climbStairs(int n) {

    }
};


int main()
{
    Solution so;
    cout << so.climbStairs(10);
}
