# Jump Game II

**Topic:** Greedy  
**Difficulty:** Medium  
**LeetCode URL:** https://leetcode.com/problems/jump-game-ii/

---

## Problem Statement

You are given a **0-indexed** array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.

Each element `nums[i]` represents the **maximum length of a forward jump** from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where `0 <= j <= nums[i]`.

Return *the minimum number of jumps to reach* `nums[n - 1]`.

The test cases are generated such that you can always reach `nums[n - 1]`.

---

## Examples

**Example 1:**
```
Input:  nums = [2, 3, 1, 1, 4]
Output: 2
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**
```
Input:  nums = [2, 3, 0, 1, 4]
Output: 2
```

---

## Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- The answer is guaranteed to exist.

---

## Hints

1. Think of the problem in "levels" — similar to BFS levels in a graph.
2. At each jump, greedily choose the farthest reachable index.
3. You only increment the jump count when you **must** move to the next level (i.e., you've exhausted the current range).

---

## Approach: Greedy (BFS-style)

```python
def jump(nums: list[int]) -> int:
    jumps = 0
    current_end = 0   # end of current jump range
    farthest = 0      # farthest index reachable so far

    for i in range(len(nums) - 1):  # don't need to jump FROM last index
        farthest = max(farthest, i + nums[i])

        if i == current_end:        # reached end of current level
            jumps += 1
            current_end = farthest  # expand to farthest reachable

    return jumps
```

### Complexity
| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

---

## Walkthrough — Example 1: `[2, 3, 1, 1, 4]`

| i | nums[i] | farthest | current_end | jumps |
|---|---------|----------|-------------|-------|
| 0 | 2       | 2        | 0 → 2       | 1     |
| 1 | 3       | 4        | 2           | 1     |
| 2 | 1       | 4        | 2 → 4       | 2     |
| 3 | 1       | 4        | 4           | 2     |

Answer: **2** ✅

---

## Common Mistakes

- Iterating all the way to `n-1` in the loop (causes an extra jump count).
- Confusing `current_end` (boundary of current jump) with `farthest` (best we *could* reach).
- Using DP instead of greedy — works but is O(n²).
