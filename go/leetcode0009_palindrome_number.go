/**
* @Author: Charles
* @Date: 2019/11/11 2:30
* @Description:
* @File:  leetcode0009_palindrome_number
* @Version: 1.0.0
**/
package main

import "fmt"

func isPalindrome(x int) bool {
	if x >= 0 && x <= 9 {
		return true
	}

}



func main() {
	var checkArray = [5]int{2, 121, -121, 1221, -1221}
	var expected = [5]bool{true, true, false, true, false}
	for i := 0; i < len(checkArray); i++ {
		checkRet := isPalindrome(checkArray[i])
		if checkRet != expected[i] {
			fmt.Printf("input[%d], expected[%t], but acctual[%t]",
				checkArray[i], expected[i], checkRet)
		}
	}
}
