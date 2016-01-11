#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;
/*
 *  利用一个map保存已经访问过的元素和对应的访问次数，再利用一个index变量保存已经访问过的，但是没有重复的元素个数
 *  每访问一个元素先查询map是否已经访问过了，如果访问过了则略过，再次遍历，如果没有访问过，则插入map，并累加index
 *
 *
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    		//建立一个map,保存访问过的元素，维护一个index，为当前数组不重复元素的下标
    		map<int,bool> visited;
			int index = 0;
			for(int i = 0;i < nums.size();i++)
			{
				pair<map<int,bool>::iterator,bool> ret = visited.insert(make_pair(nums[i],true));
				if (ret.second) { //插入成功
                    nums[index] = nums[i];
					index++;
				} else { //插入失败
					//有重复，什么也不做.
					continue;
				}
			}
			return index;
    }
};


/*
 *  C++11实现简化了代码
 *
 */
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,bool> visted;
        int index = 0;
        for(auto num : nums)
        {
            auto ret = visted.insert(make_pair(num,true));
            if(ret.second) {
                nums[index] = num;
                index++;
            } else {
                continue;
            }
        }
        return index;
    }
};


/*
 *  先排序，然后顺序遍历一趟即可
 *
 *
 */

class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index = 0;
        for(int i = 1; i < nums.size();++i)
        {
            if (nums[i] != nums[i-1])
                nums[++index] = nums[i];
            else
                continue;
        }
        return index+1;
    }
};


/*
 *  使用STL算法
 *
 *
 */
int main()
{
    vector<int> num;
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    Solution so;
    Solution2 so2;
    Solution3 so3;
    assert(so.removeDuplicates(num) == 4);
    assert(so2.removeDuplicates(num) == 4);
    assert(so3.removeDuplicates(num) == 4);
}
