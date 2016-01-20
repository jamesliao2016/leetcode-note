#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        count = 0
        for index in xrange(len(nums)):
            if nums[index] == val:
                continue
            else:
                nums[count] = nums[index]
                count += 1
        return count

class Solution2(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        try:
            while True:
                nums.remove(val)
        except ValueError as e:
            return len(nums)

if __name__ == "__main__":

