#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <limits.h>

using namespace std;

/*
 *  先排序再夹逼
 *  思路和3sum一致，只不过这题需要返回和目标数字最接近的的值，所以可以全局维护一个值
 *
 *
 *
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3) return nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        int min_gap = INT_MAX;
        int result = 0;
        for(int i = 0; i < nums.size() - 2; ++i) {
            int first = i + 1;
            int last = nums.size() - 1;
            while(first < last) {
                //最终要返回的结果
                const int sum = nums[i] + nums[first] + nums[last];
                //计算差值
                const int gap = abs(sum - target);
                //确定最小差值和返回的结果
                if(gap < min_gap) {
                    result = sum;
                    min_gap = gap;
                }
                //根据sum来确定如何逼近，是从左，还是从右
                if(sum < target) ++first;
                else --last;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> num = {1,1,1,1};
    Solution so;
    cout << so.threeSumClosest(num,0) << endl;
}
