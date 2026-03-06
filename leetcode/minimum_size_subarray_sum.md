# Minimum Size Subarray Sum

**Topic:** Sliding Window  
**Difficulty:** Medium  
**LeetCode URL:** https://leetcode.com/problems/minimum-size-subarray-sum/

---

## Problem Statement

Given an array of positive integers `nums` and a positive integer `target`, return the **minimal length** of a subarray whose sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.

---

## Examples

**Example 1:**
```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

**Example 2:**
```
Input: target = 4, nums = [1,4,4]
Output: 1
```

**Example 3:**
```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

---

## Constraints

- `1 <= target <= 10^9`
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

---

## Approach: Sliding Window (Two Pointers)

Use a **variable-size sliding window** with two pointers (`left` and `right`):

1. Expand the window by moving `right` forward and adding `nums[right]` to the current sum.
2. When the current sum `>= target`, record the window size and shrink from the left by moving `left` forward.
3. Keep shrinking as long as the condition still holds.
4. Track the minimum window length throughout.

This runs in **O(n)** time since each element is added and removed at most once.

---

## Solution

```python
def minSubArrayLen(target: int, nums: list[int]) -> int:
    left = 0
    current_sum = 0
    min_len = float('inf')

    for right in range(len(nums)):
        current_sum += nums[right]

        while current_sum >= target:
            min_len = min(min_len, right - left + 1)
            current_sum -= nums[left]
            left += 1

    return 0 if min_len == float('inf') else min_len
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | O(n) — each element visited at most twice |
| **Space** | O(1) — only a few variables used |

---

## Follow-up

Can you solve it in **O(n log n)** time using binary search?  
*Hint: Use prefix sums and binary search for the smallest index where prefix_sum >= target + prefix_sum[left].*

```python
import bisect

def minSubArrayLen(target: int, nums: list[int]) -> int:
    prefix = [0]
    for n in nums:
        prefix.append(prefix[-1] + n)

    min_len = float('inf')
    for i in range(1, len(prefix)):
        t = target + prefix[i - 1]
        j = bisect.bisect_left(prefix, t)
        if j < len(prefix):
            min_len = min(min_len, j - (i - 1))

    return 0 if min_len == float('inf') else min_len
```
