#!/usr/bin/env python
# encoding: utf-8


## 利用set的特性，将列表转换为list，最高效的实现
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        setnums
        #setnums = list(set(nums))
        setnums.sort(key=nums.index)
        nums = setnums[:]
        return len(setnums);


if __name__ == "__main__":
    so = Solution()
    l = [3,4,5,6,1,3,5,6]
    assert so.removeDuplicates(l) == 5
    print(l)
