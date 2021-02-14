/*
 * @lc app=leetcode id=933 lang=golang
 *
 * [933] Number of Recent Calls
 */
package Go

// @lc code=start
type RecentCounter struct {
	timeTS []int
}

func Constructor() RecentCounter {
	return RecentCounter{}
}

func (this *RecentCounter) Ping(t int) int {
	this.timeTS = append(this.timeTS, t)
	a := BinarySearch(this.timeTS, t-3000)
	b := len(this.timeTS)
	return b - a
}

func BinarySearch(N []int, n int) int {
	start, end := 0, len(N)-1
	for start <= end {
		mid := start + (end-start)/2
		if N[mid] < n {
			start = mid + 1
		} else if N[mid] > n {
			end = mid - 1
		} else {
			return mid
		}
	}
	return start
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
// @lc code=end
