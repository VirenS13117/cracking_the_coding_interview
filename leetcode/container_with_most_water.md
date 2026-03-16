# Container With Most Water

**Topic:** Two Pointers  
**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/container-with-most-water/

---

## Problem Statement

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i-th` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the **maximum amount of water** a container can store.

> You may **not** slant the container.

---

## Examples

**Example 1:**
```
Input:  height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by the array.
             The max area is formed between index 1 (height=8) and
             index 8 (height=7): min(8,7) * (8-1) = 7 * 7 = 49
```

**Example 2:**
```
Input:  height = [1,1]
Output: 1
```

---

## Constraints

- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

---

## Hints

<details>
<summary>Hint 1</summary>
A brute-force O(n²) solution checks every pair of lines. Can you do better?
</details>

<details>
<summary>Hint 2</summary>
Start with the widest possible container (left = 0, right = n-1). What determines whether you should move the left or right pointer inward?
</details>

<details>
<summary>Hint 3</summary>
The area is limited by the **shorter** of the two lines. Moving the pointer on the shorter side is the only way you could possibly find a larger area. Moving the taller side can only decrease (or maintain) the width while keeping the height bounded by the same shorter line.
</details>

---

## Approach: Two Pointers — O(n) Time, O(1) Space

```
1. Initialize left = 0, right = n - 1, max_area = 0.
2. While left < right:
   a. Compute area = min(height[left], height[right]) * (right - left)
   b. Update max_area if area is larger.
   c. Move the pointer pointing to the SHORTER line inward.
      (If equal, move either pointer.)
3. Return max_area.
```

**Why it works:** We start with maximum width. The only chance to increase area is to find a taller line on the shorter side — so we move that pointer inward. We never miss the optimal pair because discarding the shorter-side pointer can never lead to a better answer with its current partner or any inner partner.

---

## Solution (Python)

```python
from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_area = 0

        while left < right:
            # Water level is bounded by the shorter line
            current_area = min(height[left], height[right]) * (right - left)
            max_area = max(max_area, current_area)

            # Move the pointer at the shorter line inward
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1

        return max_area
```

---

## Solution (Java)

```java
class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = Math.min(height[left], height[right]) * (right - left);
            maxArea = Math.max(maxArea, currentArea);

            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
}
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | O(n) — single pass with two pointers |
| **Space** | O(1) — no extra data structures |

---

## Common Mistakes

- **Moving the wrong pointer:** Always move the pointer at the *shorter* line. Moving the taller one guarantees we can't do better with that pair.
- **Off-by-one on width:** Width = `right - left` (not `right - left + 1`), because we're measuring horizontal distance between the lines, not counting indices.
- **Forgetting to update max before moving:** Compute and record the area *before* advancing a pointer.

---

## Related Problems

- [Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water/) — similar two-pointer intuition but accumulates trapped water at each index
- [Two Sum II (Medium)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) — classic two-pointer on a sorted array
