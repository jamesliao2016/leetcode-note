#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        data_map = {}
        for num in xrange(len(nums)):
            dst = target - nums[num]
            if data_map.has_key(nums[num]):
                return [data_map[nums[num]],num+1]
            else:
                data_map[dst] = num + 1



if __name__ == "__main__":
    num = [2,7,11,15]
    so = Solution()
    print(so.twoSum(num,13))
