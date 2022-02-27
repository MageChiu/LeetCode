/*
 * @Author: Charles
 * @LastEditors: Charles
 * @Description: file content
 */

package main

import (
	"fmt"
)

func main() {
	dd := []int{
		1, 2, 3, 4, 0, 0, 0, 5, -1, 6, 1, 2, 3,
	}
	k := 4
	fmt.Printf("get ret:%v\n", findMaxLen(dd, k))
}

func findMaxLen(nums []int, target int) int {
	var s int = 0
	sumPos := make(map[int]int)
	var res int = -1
	for i := range nums {
		s += nums[i]
		tLen := -1
		if s == target {
			tLen = 1
		} else if v, ok := sumPos[s-target]; ok {
			tLen = i - v
		}
		if tLen > res {
			res = tLen
			fmt.Printf("====>%d : %d\n", i, tLen)
		}

		if _, ok := sumPos[s]; !ok {
			sumPos[s] = i
		}

	}
	for i, j := range sumPos {
		fmt.Printf("pos[%d]=%d\n", i, j)
	}
	return res
}
