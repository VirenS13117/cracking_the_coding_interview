# Trapping Rain Water

**Topic:** Two Pointers  
**Difficulty:** Hard  
**LeetCode:** [https://leetcode.com/problems/trapping-rain-water/](https://leetcode.com/problems/trapping-rain-water/)

---

## Problem Statement

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:**
```
Input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

**Example 2:**
```
Input:  height = [4,2,0,3,2,5]
Output: 9
```

**Constraints:**
- `n == height.length`
- `1 <= n <= 2 * 10^4`
- `0 <= height[i] <= 10^5`

---

## Hints

<details>
<summary>Hint 1</summary>
The water trapped above any index <code>i</code> is determined by:
<code>min(max_height_left, max_height_right) - height[i]</code>.
How can you efficiently track these max heights?
</details>

<details>
<summary>Hint 2</summary>
Use two pointers starting from both ends. Maintain <code>left_max</code> and <code>right_max</code>.
Whichever side has the smaller max, process that side — the trapped water there is already determined.
</details>

<details>
<summary>Hint 3</summary>
If <code>left_max <= right_max</code>, the water at <code>left</code> is <code>left_max - height[left]</code>.
Move the left pointer inward. Otherwise do the symmetric operation on the right.
</details>

---

## Approach: Two Pointers — O(n) Time, O(1) Space

```python
def trap(height: list[int]) -> int:
    left, right = 0, len(height) - 1
    left_max, right_max = 0, 0
    water = 0

    while left < right:
        if height[left] <= height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                water += right_max - height[right]
            right -= 1

    return water
```

---

## Step-by-Step Walkthrough

For `height = [4, 2, 0, 3, 2, 5]`:

| Step | left | right | left_max | right_max | water |
|------|------|-------|----------|-----------|-------|
| init | 0    | 5     | 0        | 0         | 0     |
| 1    | 0    | 5     | 4        | 0         | 0     |
| 2    | 1    | 5     | 4        | 5         | 0     |
| 3    | 1    | 4     | 4        | 5         | 2     |
| 4    | 2    | 4     | 4        | 5         | 6     |
| 5    | 3    | 4     | 4        | 5         | 9     |

**Result: 9** ✓

---

## Common Mistakes

- ❌ Forgetting that trapped water can never be negative — always take `max(0, ...)`.
- ❌ Using `O(n)` extra space with prefix max arrays (valid but not optimal).
- ❌ Moving the wrong pointer — always move the pointer on the side with the **smaller** max.

---

## Complexity

| | Complexity |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
