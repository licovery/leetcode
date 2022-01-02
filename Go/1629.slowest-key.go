/*
 * @lc app=leetcode id=1629 lang=golang
 *
 * [1629] Slowest Key
 */

// @lc code=start
func slowestKey(releaseTimes []int, keysPressed string) byte {
	if len(releaseTimes) != len(keysPressed) {
		return 0
	}
	var ans byte
	var maxDuration int = 0
	var last int = 0
	for i, cur := range releaseTimes {
		d := cur - last
		if d >= maxDuration {
			if d == maxDuration {
				// lexicographically largest
				if keysPressed[i] > ans {
					ans = keysPressed[i]
				}
			} else {
				ans = keysPressed[i]
			}
			// longest duration
			maxDuration = d
		}
		last = cur
	}
	return ans
}

// @lc code=end
