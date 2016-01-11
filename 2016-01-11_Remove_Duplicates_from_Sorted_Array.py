#!/usr/bin/env python
# encoding: utf-8


class Solution2(object):
    """
        利用字典的key是不重复的特性，去除重复，然后重新修改nums列表
        这题也可以换成利用set来去除重复,但是无论是基于set还是基于字典都存在一个问题就是去除重复后相对顺序变了
        因为字典和集合都是无序的，为了解决这个问题网上可以搜索到的解决方案就是基于原有的列表来排序也就是下面这段代码
        >>> l = [1,2,4,3]
        >>> new_l = list(set(l))
        >>> new_l.sorted(key=l.index)

        但是排序的这种方式效率太低，后来发现使用有序字典来实现效率要高出很多，下面是基于有序字典的方式去除重复，并且保证是有序的。
        但是因为本题的目的不仅仅是去除重复，还需要修改原有的列表，因此基于这种方案效率没有下面的效率高。
    """
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
	import collections
	d = collections.OrderedDict()
	num = d.fromkeys(nums).keys()
	lens = len(num)
	for i in xrange(lens):
		nums[i] = num
        return lens

class Solution(object):
    """
        基本思路相邻位置比较，使用一个curr记录不重复的数字个数
    """
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
	if not nums:
		return 0
	n = len(nums)
	count = curr = 1
	while count < n:
		if nums[curr] != nums[curr -1]:
			curr += 1
		else:
			del nums[curr]
		count +=1
	return curr



if __name__ == "__main__":
	so = Solution()
	l = [1,2,3,5]
	a = so.removeDuplicates(l)
	print(a)
