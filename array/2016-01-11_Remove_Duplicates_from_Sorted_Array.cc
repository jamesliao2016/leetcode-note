#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <iterator>

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
 *  先使用unique，将重复的元素全部移动到末尾，然后返回指向末尾第一个重复的数字的一个迭代器
 *  然后使用distance计算vector开始元素和返回的迭代器之间的距离
 *  需要注意unique算法只能删除相邻元素重复的
 *
 */
class Solution4 {
public:
    int removeDuplicates(vector<int>& nums)
    {
        return distance(nums.begin(),unique(nums.begin(),nums.end()));
    }
};


/*
 *  upper_bound是返回第一个大于指定数的迭代器
 *
 *
 */
class Solution5 {
public:
    int removeDuplicates(vector<int>& nums)
    {
        return removeDuplicates(nums.begin(),nums.end(),nums.begin()) - nums.begin();
    }

    template<typename InIt,typename OutIt>
    OutIt removeDuplicates(InIt first,InIt last,OutIt output) {
        while(first != last) {
            *output++ = *first;
            first = upper_bound(first,last,*first);
        }
        return output;
    }
};

int main()
{
    vector<int> num;
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    Solution so;
    Solution2 so2;
    Solution3 so3;
    Solution4 so4;
    Solution5 so5;
    assert(so.removeDuplicates(num) == 4);
    assert(so2.removeDuplicates(num) == 4);
    assert(so3.removeDuplicates(num) == 4);
    assert(so4.removeDuplicates(num) == 4);
    assert(so5.removeDuplicates(num) == 4);
}
