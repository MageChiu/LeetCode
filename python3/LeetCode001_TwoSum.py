#!/bin/env python3
# LeetCode001_TwoSum.py
# @author zhaopeng
# @description 
# @created 2020-05-31T02:56:52.477Z+08:00
# @last-modified 2020-06-12T01:09:13.035Z+08:00
#


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        tmp = {}
        for i in nums:
            if i in tmp.keys():
                return [tmp[i], i]
            else:
                tmp[target - i] = i
        return []

if __name__ == "__main__":
    so = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    res = so.twoSum(nums, target)
    print(res)


        