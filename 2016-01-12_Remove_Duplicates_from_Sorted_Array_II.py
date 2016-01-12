#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 2:
            return len(nums)
        count = 0;
        curr_cnt = 0
        for index in range(1,len(nums)):
            if nums[index] == nums[index - 1]:
                curr_cnt += 1
                if curr_cnt >= 2:
                    continue;
                else:
                    count += 1;
                    nums[count] = nums[index]
            else:
                curr_cnt = 0
                count += 1
                nums[count] = nums[index]

        return count + 1

if __name__ == "__main__":
    l = [1,1,1,2,2,3,3,3,3,3,3]
    so = Solution()
    print(so.removeDuplicates(l))
