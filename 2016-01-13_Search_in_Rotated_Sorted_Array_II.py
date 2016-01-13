#!/usr/bin/env python
# encoding: utf-8


#二分查找
class Solution2(object):
    def search(self,nums,target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        first = 0
        last = len(nums)
        mid = 0
        while first != last:
            mid = (first + last) / 2
            if nums[mid] == target:
                return True
            if nums[mid] > nums[first]:   #左侧连续
                if target < nums[mid] and target >= nums[first]:
                    last = mid
                else:
                    first = mid + 1
            elif nums[mid] < nums[first]: #右侧连续
                if target > nums[mid] and target <= nums[last - 1]:
                    first = mid + 1
                else:
                    last = mid
            else:                         #不确定
                first += 1
        return False



#内置inde直接实现
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        try:
            nums.index(target)
            return True
        except ValueError:
            return False

if __name__ == "__main__":
    l = [1,3,1,1,1]
    so = Solution()
    so2 = Solution2()
    assert so.search(l,1) == True
    assert so.search(l,2) == False
    assert so2.search(l,1) == True
    assert so2.search(l,2) == False
