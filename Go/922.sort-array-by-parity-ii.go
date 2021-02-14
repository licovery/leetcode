/*
 * @lc app=leetcode id=922 lang=golang
 *
 * [922] Sort Array By Parity II
 */
package Go

// @lc code=start
func sortArrayByParityII(A []int) []int {
	isOdd := func(n int) bool {
		if n%2 == 0 {
			return false
		} else {
			return true
		}
	}

	var oddList, evenList []int
	for _, a := range A {
		if isOdd(a) {
			oddList = append(oddList, a)
		} else {
			evenList = append(evenList, a)
		}
	}

	ret := make([]int, 0, len(A))
	for i := range oddList {
		ret = append(ret, evenList[i], oddList[i])
	}
	return ret
}

// @lc code=end
