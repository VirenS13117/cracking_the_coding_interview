# Decode Ways

**Topic:** Dynamic Programming  
**Difficulty:** Medium  
**LeetCode:** [https://leetcode.com/problems/decode-ways/](https://leetcode.com/problems/decode-ways/)

---

## Problem Statement

A message containing letters `'A'` to `'Z'` can be encoded into numbers using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```

Given a string `s` containing only digits, return the **number of ways** to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

---

## Examples

**Example 1:**
```
Input:  s = "12"
Output: 2
Explanation: "12" can be decoded as "AB" (1 2) or "L" (12).
```

**Example 2:**
```
Input:  s = "226"
Output: 3
Explanation: "226" can be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

**Example 3:**
```
Input:  s = "06"
Output: 0
Explanation: "06" cannot be decoded because "06" != "6" (leading zero).
```

---

## Constraints

- `1 <= s.length <= 100`
- `s` contains only digits
- `s` may contain leading zeros

---

## Approach: Bottom-Up Dynamic Programming

### Intuition

Define `dp[i]` = number of ways to decode the first `i` characters of `s`.

- **Base case:** `dp[0] = 1` (empty string has one way — do nothing)
- **Single digit:** If `s[i-1] != '0'`, then `dp[i] += dp[i-1]`
- **Two digits:** If `10 <= int(s[i-2:i]) <= 26`, then `dp[i] += dp[i-2]`

### Walkthrough: `s = "226"`

```
dp = [1, 0, 0, 0]  # length n+1

i=1: s[0]='2' != '0'  → dp[1] += dp[0] = 1        → dp=[1,1,0,0]
i=2: s[1]='2' != '0'  → dp[2] += dp[1] = 1
      "22" = 22 in [10,26] → dp[2] += dp[0] = 1    → dp=[1,1,2,0]
i=3: s[2]='6' != '0'  → dp[3] += dp[2] = 2
      "26" = 26 in [10,26] → dp[3] += dp[1] = 1    → dp=[1,1,2,3]

Answer: dp[3] = 3 ✓
```

---

## Solution

```python
def numDecodings(s: str) -> int:
    n = len(s)
    dp = [0] * (n + 1)
    dp[0] = 1  # Base case: empty string

    for i in range(1, n + 1):
        # Single digit decode
        if s[i - 1] != '0':
            dp[i] += dp[i - 1]

        # Two digit decode
        if i >= 2:
            two_digit = int(s[i - 2:i])
            if 10 <= two_digit <= 26:
                dp[i] += dp[i - 2]

    return dp[n]
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | O(n) — single pass through the string |
| **Space** | O(n) — dp array of size n+1 |

> **Space Optimization:** Since `dp[i]` only depends on `dp[i-1]` and `dp[i-2]`, you can reduce space to **O(1)** using two variables.

```python
def numDecodings(s: str) -> int:
    prev2, prev1 = 1, 0

    if s[0] != '0':
        prev1 = 1

    for i in range(1, len(s)):
        curr = 0
        if s[i] != '0':
            curr += prev1
        two_digit = int(s[i - 1:i + 1])
        if 10 <= two_digit <= 26:
            curr += prev2
        prev2, prev1 = prev1, curr

    return prev1 if len(s) > 1 else (1 if s[0] != '0' else 0)
```

---

## Edge Cases to Watch

| Input | Output | Reason |
|---|---|---|
| `"0"` | `0` | No valid encoding starts with 0 |
| `"10"` | `1` | Only `"J"` (10) |
| `"30"` | `0` | 30 > 26, and `'0'` alone is invalid |
| `"100"` | `0` | `"10"` + `"0"` — `'0'` is invalid alone |
