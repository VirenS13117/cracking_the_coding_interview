# Longest Consecutive Sequence

**Topic:** Hash Table  
**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/longest-consecutive-sequence/

---

## Problem Statement

Given an unsorted array of integers `nums`, return the length of the **longest consecutive elements sequence**.

You must write an algorithm that runs in **O(n)** time.

---

## Examples

**Example 1:**
```
Input:  nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive sequence is [1, 2, 3, 4]. Length = 4.
```

**Example 2:**
```
Input:  nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation: The longest consecutive sequence is [0,1,2,3,4,5,6,7,8]. Length = 9.
```

---

## Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

## Approach: Hash Set

### Key Insight
Only **start** counting a sequence from a number `n` if `n - 1` is **not** in the set.  
This ensures each sequence is only traversed once → O(n) overall.

### Steps
1. Add all numbers into a `HashSet` for O(1) lookups.
2. Iterate through each number. If `num - 1` is **not** in the set, it's the start of a sequence.
3. From that start, keep incrementing and checking how far the streak goes.
4. Track the maximum streak length.

### Complexity
- **Time:** O(n) — each number is visited at most twice
- **Space:** O(n) — for the hash set

---

## Solution

```python
def longestConsecutive(nums: list[int]) -> int:
    num_set = set(nums)
    longest = 0

    for num in num_set:
        # Only start counting from the beginning of a sequence
        if num - 1 not in num_set:
            current = num
            streak = 1

            while current + 1 in num_set:
                current += 1
                streak += 1

            longest = max(longest, streak)

    return longest
```

---

## Walkthrough: Example 1

```
nums   = [100, 4, 200, 1, 3, 2]
num_set = {1, 2, 3, 4, 100, 200}

- num=1:   1-1=0 not in set → start! streak: 1→2→3→4 = 4
- num=100: 99 not in set   → start! streak: 100 = 1
- num=200: 199 not in set  → start! streak: 200 = 1
- num=2:   1 in set        → skip
- num=3:   2 in set        → skip
- num=4:   3 in set        → skip

Answer: 4 ✓
```

---

## Common Mistakes

| Mistake | Fix |
|---|---|
| Sorting the array (O(n log n)) | Use a hash set for O(n) |
| Iterating `nums` instead of `num_set` | Duplicates waste work; iterate the set |
| Not checking `num - 1 not in set` | You'll recount streaks from the middle |

---

## Edge Cases

```python
longestConsecutive([])        # → 0  (empty array)
longestConsecutive([1])       # → 1  (single element)
longestConsecutive([1,1,1])   # → 1  (all duplicates)
longestConsecutive([-1,0,1])  # → 3  (negative numbers)
```
