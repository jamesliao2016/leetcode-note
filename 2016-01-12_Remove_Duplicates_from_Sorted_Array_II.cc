#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

/*
 *  map维护每个元素访问的次数,利用了map的一个特性使用[]访问map元素的时候，如果元素不存在会自动插入，初始化为0
 *  但是这种解法并不是很好，因为题目给出的是数组是已经排好序的。
 *
 *
 */
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
    	    if (nums.size() <= 2)
                return nums.size();
            map<int,int> visited;
    	    int index = 0;
    	    for(int i = 0; i < nums.size(); i++)
    	    {
    		    if (visited[nums[i]] <= 1) {
    			    visited[nums[i]]++;
    			    nums[index++] = nums[i];
    		    } else {
    			    visited[nums[i]]++;
    		    }
    	    }
    	    return index;
        }
};


class Solution2 {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() <= 2)
                return nums.size();
            int count = 0;
            int curr_cnt = 0;
            for(int i = 1; i < nums.size(); i++)
            {
                if (nums[i] == nums[i - 1]) {
                    ++curr_cnt;
                    if (curr_cnt >= 2) {
                        continue;
                    } else {
                        nums[++count] = nums[i];
                    }
                }else {
                    curr_cnt = 0;
                    nums[++count] = nums[i];
                }
            }
            return count+1;
        }
};

/*
 *  这个解法明显比上面的解法更容易看懂和理解，上面的解法太过繁琐。
 *  这个解法的基本思路就是通过nums[i] != nums[index -2]保证不会出现三个或者三个以上的元素重复出现
 *  index是此时不重复出现二次的数组即将要待存放元素的位置，i则是遍历到的元素即将要放入待存放位置。
 *  这种解法思路较清晰，并且扩展性也很好。
 */
class Solution3 {
    public:
        int removeDuplicates(vector<int>& nums)
        {
            if (nums.size() <= 2)return nums.size();
            int index = 2;
            for(int i = 2; i < nums.size(); i++){
                if (nums[i] != nums[index - 2])
                    nums[index++] = nums[i];
            }
            return index;
        }
};


/*
 *
 *  下面这种解法代码更少，但是不具备扩展性，基本思路就是一个重复三次或者三次以上的数字，一定满足
 *  nums[i] == nums[i - 1]  && nums[i] == nums[i+1]，也就是除去这个重复数字的起始和结束位置外，其它位置都满足这个等式，那么只要在循环中判断
 *  如果满足这个等式就略过，这样最终的效果就是对于一串连续的重复数字，只取头和尾。这个解法的另外一个关键点就是把握好边界条件。第一个元素和最后
 *  一个元素是不需要使用这个等式进行判断的，因为这两个数字没有前驱或者没有后继
 *
 *
 */

class Solution4 {
    public:
        int removeDuplicates(vector<int>& nums)
        {
            int index = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if (i > 0 && i < (nums.size()-1) && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
                        continue;
                nums[index++] = nums[i];
            }
            return index;
        }
};

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    num.push_back(3);
    num.push_back(3);
    num.push_back(3);
    num.push_back(3);
    num.push_back(3);
    Solution2 so2;
    Solution3 so3;
    Solution4 so4;
    //assert(so2.removeDuplicates(num) == 6);
    //assert(so3.removeDuplicates(num) == 6);
    assert(so4.removeDuplicates(num) == 6);
}
