#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;
/*
 *  这一题难度较大，初想起来真不好解决
 *  解决这题的最好算法就是贪心算法用一个vector increment来存放所有的小孩得到的糖果数
 *  第一个小孩给一个糖果，如果第二个小孩分数大于第一个小孩，那么第二个小孩就是２个糖果，以此类推，如果到达某个小孩
 *  不比他上一个小孩的分数高，那么这个小孩就得到一个糖果，以此重复:
 *  例如: 1 2 1 4 5 6 4
 *  那么得到的糖果
 *
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> increment(n);

        //左右各扫描一遍
        for(int i = 1,inc = 1;i < n; ++i) {
            if(ratings[i] > ratings[i - 1])
                increment[i] = max(inc++,increment[i]);
            else
                inc = 1;
        }

        for(int i = n - 2,inc = 1;i >= 0; i--) {
            if(ratings[i] > ratings[i + 1])
                increment[i] = max(inc++,increment[i]);
            else
                inc = 1;
        }
        return accumulate(&increment[0],&increment[0]+n,n);
    }
};

int main()
{

}
