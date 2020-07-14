/**
* @Author: Charles
* @Date: 2020/1/14 1:09
* @Description:
* @File:  leetcode00704_bst
* @Version: 1.0.0
**/
package main

func search(nums []int, target int) int {
	start := 0
	end := len(nums) - 1
	for ; start <= end; {
		mid := start + (end - start) / 2
		if (nums[mid] > target) {
			end = mid - 1
		} else if (nums[mid] < target) {
			start = mid + 1
		} else {
			return mid
		}
	}
	return -1
}

func main() {
	
}
