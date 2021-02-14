/*
 * @lc app=leetcode id=937 lang=golang
 *
 * [937] Reorder Data in Log Files
 */
package Go

import (
	"sort"
	"strings"
	"unicode"
)

// @lc code=start
type LogType int

const (
	LogTypeLetter LogType = 1
	LogTypeDigit  LogType = 2
)

func reorderLogFiles(logs []string) []string {
	var digitLogs []string
	ret := make([]string, 0, len(logs))

	for _, log := range logs {
		if getLogType(log) == LogTypeDigit {
			digitLogs = append(digitLogs, log)
		} else {
			ret = append(ret, log)
		}
	}

	sort.Slice(ret, func(i, j int) bool {
		idI, contentI := parseLog(ret[i])
		idJ, contentJ := parseLog(ret[j])

		cmp := strings.Compare(contentI, contentJ)
		if cmp == -1 {
			return true
		} else if cmp == 1 {
			return false
		}

		cmp = strings.Compare(idI, idJ)
		if cmp == -1 {
			return true
		} else if cmp == 1 {
			return false
		}
		return true
	})

	ret = append(ret, digitLogs...)

	return ret
}

func parseLog(log string) (string, string) {
	words := strings.Split(log, " ")
	return words[0], strings.Join(words[1:], " ")
}

func getLogType(log string) LogType {
	words := strings.Split(log, " ")
	// logs[i] is guaranteed to have an identifier and at least one word after the identifier.
	if unicode.IsLetter(rune(words[1][0])) {
		return LogTypeLetter
	} else {
		return LogTypeDigit
	}
}

// @lc code=end
