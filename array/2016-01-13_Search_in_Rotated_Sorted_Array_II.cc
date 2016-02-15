#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;
/*
 *  相比于Search in Rotated Sorted Array 略微复杂了一点
 *  在Search in Rotated Sorted Array这套题中只需要确定nums[mid] >= nums[first]就可以判定左侧都是连续的,但是如果允许有序数组重复,那么这个
 *  结论就不成立了,例如[1,3,1,1,1,1] 很明显mid是等于first的,但是左侧并非连续,因此在这种情况下,需要将nums[mid] >= nums[first]这个条件拆开
 *  nums[mid] > nums[first] 则左侧一定连续
 *  nums[mid] = nums[first] 则不能确定.需要拿nums[mid] 和 nums[++first]比较知道不想等为止
 *
 *
 *
 */
class Solution {
    public:
    bool search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size();
        int mid = 0;
        while(first != last) {
            mid = (first + last) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[first]) {
                if (target < nums[mid] && target >= nums[first])
                    last = mid;
                else
                    first = mid + 1;

            } else if(nums[mid] < nums[first]) {
                if (target > nums[mid] && target <= nums[last - 1])
                    first = mid + 1;
                else
                    last = mid;

            } else {
                ++first;
            }
        }
        return false;
    }

};

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    Solution so;
    assert(so.search(num,3) == true);
    assert(so.search(num,2) == false);
}
