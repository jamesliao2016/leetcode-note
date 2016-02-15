#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <vector>

using namespace std;

/*
 * 解题思路:
 *  思路1: 先将元素全部保存在map中，让偶固定一个元素．遍历剩下的元素，每遍历到一个元素，计算最后一个元素的值，然后去,map中查找
 *  思路1实现起来不难，但是要求就是数组中不能出现重复数字，因此可以略过
 *
 *  思路2: 先将元素排序，然后固定一个元素，然后使用两个指针，指向固定元素的次一个(first)，后最后一个元素(last)．
 *  当0 - 固定元素 - first > last，那么++first，否则last--;
 *
 *  例子: -1 0 1 2 -1 -4,排序后-1 -1 -4 0 1 2
 *  先固定-1，然后从第二个-1开始遍历
 *  first = -1,last = 2 ==> 0 - (-1) - (-1)=2　正好== last，保存结果 (-1 -1 2) --last
 *  first = -4,last = 2 ==> 0 - (-1) - (4)=5  大于last，first++
 *  first = 0,last = 2 ==> 0 - (-1) - (0) = 1 小于last，last--
 *  first = 0,last = 1 ==> 0 - (-1) - (0) = 1 正好== last，保存结果(-1,0,1) --last
 *  类比......直到first >= last 结束
 *
 *  然后固定第二个-1,first从-4,last从2开始，重复上面的步骤
 *  直到固定了一圈后结束
 *
 *  这种方式的遍历会导致一个问题就是重复，所以每次保存结果的时候，需要和上一次的结果比较，避免重复
 *  好处则是代码显而易见
 *
 *
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> data;
            for(int i = 0; i < nums.size() - 2;++i) {
                //去除重复
                if(i != 0 && nums[i] == nums[i-1])
                    continue;

                for(int j = i+1,k = (nums.size()-1); j < nums.size() && j < k;) {
                        int dest = 0 - nums[i] - nums[j];
                        if (dest == nums[k]) {
                            //和上一次进行比较，避免充重复
                            if(data.size() > 0 && nums[i] == data[data.size() - 1][0] &&
                               nums[j] == data[data.size() - 1][1] &&
                               nums[k] == data[data.size() - 1][2]) {
                                --k;
                                ++j;
                                continue;
                            }

                            vector<int> store;
                            store.push_back(nums[i]);
                            store.push_back(nums[j]);
                            store.push_back(nums[k]);
                            data.push_back(store);
                            --k;
                            ++j;
                        }
                        if(dest > nums[k])
                            ++j;
                        else
                            --k;

                }
            }
            return data;
    }
};

/*
 *  思路和解法一相同，只不过使用了另外一种避免重复的方法，比解法一避免重复的方法复杂度要小．
 *
 *
 */
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(),nums.end());
        const int target = 0;

        auto last = nums.end();
        for(auto i = nums.begin(); i < last - 2; ++i) {
            auto j = i + 1; //j总是从i的下一个位置开始
            if(i > nums.begin() && *i == *(i - 1)) continue; //去除重复
            auto k = last - 1;

            while(j < k) { //分头尾夹逼来遍历
                if(*i + *j + *k < target) { //头部开始向前递增
                    ++j;
                    while(*j == *(j - 1) && j < k) ++j; //避免重复
                } else if(*i + *j + *k > target) {
                    --k;
                    while(*k == *(k + 1) && j < k) --k; //避免重复
                } else {
                    result.push_back({*i,*j,*k});
                    ++j;
                    --k;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j; //避免重复
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> data = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution so;
    auto ret = so.threeSum(data);
    for(auto num : ret) {
        for(auto data : num) {
            cout << data << ",";
        }
        cout << endl;
    }
}
