#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


/*  思路比较简单:
 *  先保存每一个元素值及其对应的下标存放在map中
 *  然后遍历，判断target - num是否在map中．具体过程如下:
 *  nums = {2,7,11,5} target = 13
 *
 *  Step1: 建立map关系
 *      2:1
 *      7:2
 *      11:3
 *      15:4
 *  Setp2:
 *      顺序遍历
 *      遍历2，计算target - 2是否在map中，发现13 - 2 = 11在map中，记录key=11的value值
 *
 *  Setp3:
 *      构造vector返回
 *
 *  需要考虑重复元素的处理，下面这种方法，存在一个很明显的bug，就是不允许重复
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> store;
        int count = 1;
        vector<int> ret;
        for(auto num : nums) store[num] = count++;

        for(auto num : nums) {
            if(store.find(target - num) != store.end() && (target - num) != num) {
                ret.push_back(store[num]);
                ret.push_back(store[target - num]);
                break;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> num = {0,4,3,0};
    Solution so;
    vector<int> ret = so.twoSum(num,6);
    for(auto num : ret) cout << num << endl;
}
