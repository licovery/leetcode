/*
 * @lc app=leetcode id=908 lang=golang
 *
 * [908] Smallest Range I
 */
package Go

// @lc code=start
func smallestRangeI(A []int, K int) int {
	if len(A) == 0 {
		return 0
	}
	// seed
	min, max := A[0], A[0]

	for _, a := range A {
		if a < min {
			min = a
		}
		if a > max {
			max = a
		}
	}

	diff := max - min - 2*K

	if diff <= 0 {
		return 0
	}
	return diff
}

// @lc code=end
