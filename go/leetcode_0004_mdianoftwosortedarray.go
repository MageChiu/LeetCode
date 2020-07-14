/**
* @Author: Charles
* @Date: 2020/1/14 0:48
* @Description:
* @File:  leetcode_0004_mdianoftwosortedarray
* @Version: 1.0.0
**/
package main

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	l1 := len(nums1)
	l2 := len(nums2)
	m := (l1 + l2 + 1) / 2
	i := 0
	j := 0
	for  ; i + j < l1 + l2; {
		if (nums1[i] < nums2[j]) {
			i++
		} else {
			j++
		}

	}
	if ()
	if (nums1[m1] == nums1[m2]) {
		return float64(nums1[m1])
	} else if (nums1[m1] < nums2[m2]) {

	}
}

func main() {
	
}
