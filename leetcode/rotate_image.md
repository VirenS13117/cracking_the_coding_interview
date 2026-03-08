# Rotate Image

**Topic:** Matrix  
**Difficulty:** Medium  
**LeetCode URL:** https://leetcode.com/problems/rotate-image/

---

## Problem Statement

You are given an `n x n` 2D matrix representing an image. Rotate the image **90 degrees clockwise** **in-place**.

You must rotate the matrix in-place — do **not** allocate another 2D matrix.

---

## Examples

**Example 1:**
```
Input:  matrix = [[1,2,3],
                  [4,5,6],
                  [7,8,9]]

Output:          [[7,4,1],
                  [8,5,2],
                  [9,6,3]]
```

**Example 2:**
```
Input:  matrix = [[5,1,9,11],
                  [2,4,8,10],
                  [13,3,6,7],
                  [15,14,12,16]]

Output:          [[15,13,2,5],
                  [14,3,4,1],
                  [12,6,8,9],
                  [16,7,10,11]]
```

---

## Constraints

- `n == matrix.length == matrix[i].length`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`

---

## Hints

> **Hint 1:** A 90° clockwise rotation can be broken into two simpler operations. What two operations on the matrix achieve the same result?

> **Hint 2:** Try **transposing** the matrix first (swap `matrix[i][j]` with `matrix[j][i]`), then **reverse each row**.

> **Hint 3:** After transpose + reverse each row, verify with a small example:
> ```
> [[1,2,3],    transpose→   [[1,4,7],    reverse rows→   [[7,4,1],
>  [4,5,6],                  [2,5,8],                     [8,5,2],
>  [7,8,9]]                  [3,6,9]]                     [9,6,3]]
> ```

---

## Approach: Transpose + Reverse

```python
def rotate(matrix: list[list[int]]) -> None:
    n = len(matrix)

    # Step 1: Transpose the matrix (reflect over main diagonal)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: Reverse each row
    for row in matrix:
        row.reverse()
```

### Complexity
| | |
|---|---|
| **Time** | O(n²) — every cell is touched a constant number of times |
| **Space** | O(1) — in-place, no extra matrix allocated |

---

## Alternative: Four-Way Cycle Swap

Instead of two passes, directly rotate groups of 4 cells at a time in concentric rings:

```python
def rotate(matrix: list[list[int]]) -> None:
    n = len(matrix)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            # Save top
            temp = matrix[i][j]
            # Left → Top
            matrix[i][j] = matrix[n-1-j][i]
            # Bottom → Left
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
            # Right → Bottom
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
            # Top (saved) → Right
            matrix[j][n-1-i] = temp
```

Same **O(n²) time / O(1) space** — both approaches are valid in interviews.

---

## Key Takeaway

The **transpose + reverse** trick is elegant and easy to remember. Recognizing that geometric transformations on matrices can be decomposed into simpler operations is a common pattern for matrix problems.
