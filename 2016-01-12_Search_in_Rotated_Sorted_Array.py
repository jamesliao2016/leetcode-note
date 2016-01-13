#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        first = 0
        last = len(nums)
        while first != last:
            mid = (first + last) / 2
            if nums[mid] == target:
                return mid
            if nums[mid] >= nums[first]:    #左侧连续
                if target < nums[mid] and target >= nums[first]:
                    last = mid
                else:
                    first = mid + 1
            else:                           #右侧连续
                if target > nums[mid] and target <= nums[last - 1]:
                    first = mid + 1
                else:
                    last = mid
        return -1

if __name__ == "__main__":
    so = Solution()
    l = [7,8,9,1,2,3,4]
    assert so.search(l,4) == 6
    assert so.search(l,5) == -1
