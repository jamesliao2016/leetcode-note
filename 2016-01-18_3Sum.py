#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        for i in xrange(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l, r = i + 1,len(nums) - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s > 0:
                    r -= 1
                    while nums[r] == nums[r + 1] and r > l:
                        r -= 1
                elif s < 0:
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                else:
                    res.append([nums[i],nums[l],nums[r]])
                    r -= 1
                    l += 1
                    while nums[r] == nums[r + 1] and nums[l] ==  nums[l - 1] and l < r:
                        l += 1
        return res

if __name__ == "__main__":
    nums = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
    so = Solution()
    ret = so.threeSum(nums)
    for num in ret:
        print(num)
