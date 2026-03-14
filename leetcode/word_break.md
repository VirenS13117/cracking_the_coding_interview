# Word Break

**Topic:** Dynamic Programming  
**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/word-break/

---

## Problem Statement

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note:** The same word in the dictionary may be reused multiple times in the segmentation.

---

## Examples

**Example 1:**
```
Input:  s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: "leetcode" -> "leet" + "code"
```

**Example 2:**
```
Input:  s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: "applepenapple" -> "apple" + "pen" + "apple"
```

**Example 3:**
```
Input:  s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

---

## Constraints

- `1 <= s.length <= 300`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 20`
- `s` and `wordDict[i]` consist of only lowercase English letters
- All strings in `wordDict` are **unique**

---

## Approach: Bottom-Up Dynamic Programming

### Intuition
Define `dp[i]` = `True` if the substring `s[0:i]` can be segmented using words in `wordDict`.

- Base case: `dp[0] = True` (empty string)
- Transition: For each position `i`, check all positions `j < i`. If `dp[j]` is `True` **and** `s[j:i]` is in the dictionary, then `dp[i] = True`.

### Steps
1. Convert `wordDict` to a `set` for O(1) lookups.
2. Create a boolean array `dp` of size `n+1`, initialized to `False`.
3. Set `dp[0] = True`.
4. For each `i` from `1` to `n`, iterate `j` from `0` to `i`.
5. If `dp[j]` is `True` and `s[j:i]` is in the word set, set `dp[i] = True`.
6. Return `dp[n]`.

---

## Solution

```python
from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True  # empty string base case

        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break  # no need to check further

        return dp[n]
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | O(n² · m) where n = len(s), m = avg word length (substring comparison) |
| **Space** | O(n) for the dp array |

> With the word set lookup and Python string slicing, the practical complexity is O(n²) amortized for typical inputs.

---

## Optimization Tip

To further prune, you can track the **maximum word length** in the dictionary and limit how far back `j` can reach:

```python
max_len = max(len(w) for w in wordDict)
for i in range(1, n + 1):
    for j in range(max(0, i - max_len), i):
        if dp[j] and s[j:i] in word_set:
            dp[i] = True
            break
```

---

## Common Mistakes

- Forgetting the base case `dp[0] = True`
- Using a list instead of a set for `wordDict` (leads to O(n) lookup)
- Off-by-one errors in slicing `s[j:i]` vs `s[j:i+1]`

---

## Related Problems

- **Word Break II** (LeetCode 140) — return all possible segmentations
- **Decode Ways** (LeetCode 91) — similar DP structure
- **Palindrome Partitioning II** (LeetCode 132)
