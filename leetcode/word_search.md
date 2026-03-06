# Word Search

**Topic:** Backtracking  
**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/word-search/

---

## Problem Statement

Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. **The same letter cell may not be used more than once.**

---

## Examples

**Example 1:**
```
Board:
[ ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E'] ]

word = "ABCCED"  →  Output: true
word = "SEE"     →  Output: true
word = "ABCB"    →  Output: false
```

---

## Constraints

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` consist of only lowercase and uppercase English letters.

---

## Approach: DFS + Backtracking

### Key Idea
1. Iterate every cell as a potential **starting point**.
2. From each cell, do a **DFS** checking if the current character matches `word[index]`.
3. Mark a cell as **visited** before recursing (e.g., temporarily replace with `#`).
4. **Restore** the cell after recursing (backtrack).
5. Explore all 4 directions: up, down, left, right.

### Complexity
- **Time:** O(m × n × 4^L) where L = length of word
- **Space:** O(L) recursion stack depth

---

## Solution (Python)

```python
from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])

        def dfs(r, c, index):
            # All characters matched
            if index == len(word):
                return True
            # Out of bounds or character mismatch or already visited
            if (
                r < 0 or r >= rows or
                c < 0 or c >= cols or
                board[r][c] != word[index]
            ):
                return False

            # Mark as visited
            temp = board[r][c]
            board[r][c] = '#'

            # Explore all 4 directions
            found = (
                dfs(r + 1, c, index + 1) or
                dfs(r - 1, c, index + 1) or
                dfs(r, c + 1, index + 1) or
                dfs(r, c - 1, index + 1)
            )

            # Restore the cell (backtrack)
            board[r][c] = temp
            return found

        for r in range(rows):
            for c in range(cols):
                if dfs(r, c, 0):
                    return True

        return False
```

---

## Walkthrough: `word = "ABCCED"`

```
Start at (0,0) = 'A'  ✓  index=0
  → (0,1) = 'B'       ✓  index=1
    → (0,2) = 'C'     ✓  index=2
      → (1,2) = 'C'   ✓  index=3
        → (2,2) = 'E' ✓  index=4
          → (2,1) = 'D' ✓ index=5
            → index == 6 == len(word) → return True ✓
```

---

## Common Pitfalls

| Mistake | Fix |
|---|---|
| Forgetting to restore the cell | Always backtrack: `board[r][c] = temp` |
| Using a separate `visited` set | In-place marking is cleaner and avoids extra memory |
| Not checking `index == len(word)` first | Base case must come before bounds check |

---

## Edge Cases

- Single cell board matching a single character word
- Word longer than total cells → impossible
- All cells are the same character
