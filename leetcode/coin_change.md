# Coin Change

**Topic:** Dynamic Programming  
**Difficulty:** Medium  
**LeetCode URL:** https://leetcode.com/problems/coin-change/

---

## Problem Statement

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the **fewest number of coins** that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an **infinite number** of each kind of coin.

---

## Examples

**Example 1:**
```
Input:  coins = [1, 5, 10, 25], amount = 36
Output: 3
Explanation: 25 + 10 + 1 = 36 using 3 coins
```

**Example 2:**
```
Input:  coins = [1, 5, 10, 25], amount = 41
Output: 4
Explanation: 25 + 10 + 5 + 1 = 41 using 4 coins
```

**Example 3:**
```
Input:  coins = [2], amount = 3
Output: -1
```

**Example 4:**
```
Input:  coins = [1], amount = 0
Output: 0
```

---

## Constraints

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 2^31 - 1`
- `0 <= amount <= 10^4`

---

## Approach: Bottom-Up Dynamic Programming

### Intuition

Define `dp[i]` as the **minimum number of coins** needed to make amount `i`.

- **Base case:** `dp[0] = 0` (zero coins needed to make amount 0)
- **Transition:** For each amount `i` from `1` to `amount`, try every coin:
  ```
  dp[i] = min(dp[i], dp[i - coin] + 1)  for each coin <= i
  ```
- Initialize all `dp[i]` to `amount + 1` (a sentinel "infinity" value).

### Step-by-Step Example

`coins = [1, 5, 10, 25]`, `amount = 11`

```
dp[0]  = 0
dp[1]  = dp[0]  + 1 = 1   (use coin 1)
dp[5]  = dp[0]  + 1 = 1   (use coin 5)
dp[6]  = dp[5]  + 1 = 2   (use coin 1)
dp[10] = dp[0]  + 1 = 1   (use coin 10)
dp[11] = dp[10] + 1 = 2   (use coin 1)  ✓
```

---

## Solution

```python
from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[i] = min coins to make amount i
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0  # base case

        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return dp[amount] if dp[amount] <= amount else -1
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | O(amount × len(coins)) |
| **Space** | O(amount) |

---

## Common Mistakes & Tips

- ❌ **Greedy doesn't always work** — e.g., `coins = [1, 3, 4]`, `amount = 6`: greedy picks `4+1+1=3 coins`, but `3+3=2 coins` is optimal.
- ✅ Always initialize `dp` with a value **greater than** any valid answer (`amount + 1` works as infinity).
- ✅ Check `dp[amount] <= amount` before returning to detect impossible cases.
- 🔑 The key insight: **optimal substructure** — the optimal solution for `amount` builds on optimal solutions for smaller amounts.

---

## Follow-Up Questions

1. How would you reconstruct **which coins** were used (not just the count)?
2. Can you solve this with **top-down memoization (DFS + cache)**?
3. What if each coin denomination could only be used **once**? (0/1 Knapsack variant)
