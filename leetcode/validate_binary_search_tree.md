# Validate Binary Search Tree

**Topic:** Binary Trees  
**Difficulty:** Medium  
**LeetCode:** [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

---

## Problem Statement

Given the `root` of a binary tree, determine if it is a **valid binary search tree (BST)**.

A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

---

## Examples

**Example 1:**
```
    2
   / \
  1   3
```
```
Input: root = [2,1,3]
Output: true
```

**Example 2:**
```
    5
   / \
  1   4
     / \
    3   6
```
```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5, but its right child's value is 4.
```

---

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`

---

## Common Mistakes ⚠️

> Simply checking `left.val < node.val < right.val` for each node is **NOT** sufficient.  
> You must ensure **all** nodes in the left subtree are less than the current node,  
> and **all** nodes in the right subtree are greater.

---

## Approach: Recursive with Min/Max Bounds

Pass down valid `(min, max)` bounds as you recurse. Each node's value must fall **strictly** within those bounds.

```python
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validate(node, min_val, max_val):
            # Base case: empty node is valid
            if node is None:
                return True
            
            # Current node must be strictly within bounds
            if node.val <= min_val or node.val >= max_val:
                return False
            
            # Left subtree: upper bound becomes current node's value
            # Right subtree: lower bound becomes current node's value
            return (validate(node.left, min_val, node.val) and
                    validate(node.right, node.val, max_val))
        
        return validate(root, float('-inf'), float('inf'))
```

---

## Alternative Approach: In-Order Traversal

An in-order traversal of a valid BST produces a **strictly increasing** sequence.

```python
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.prev = float('-inf')
        
        def inorder(node):
            if node is None:
                return True
            if not inorder(node.left):
                return False
            if node.val <= self.prev:
                return False
            self.prev = node.val
            return inorder(node.right)
        
        return inorder(root)
```

---

## Complexity Analysis

| Approach | Time | Space |
|---|---|---|
| Min/Max Bounds | O(n) | O(h) — recursion stack |
| In-Order Traversal | O(n) | O(h) — recursion stack |

Where `n` = number of nodes, `h` = height of tree (O(log n) balanced, O(n) worst case).

---

## Key Takeaways

1. **Bounds propagation** is the cleanest mental model — each node inherits a valid range.
2. **In-order traversal** leverages the BST property that sorted order must be strictly increasing.
3. Watch out for **equal values** — a valid BST requires *strictly* less/greater (no duplicates allowed at boundaries).
4. Use `float('-inf')` and `float('inf')` as initial bounds to handle edge cases with `INT_MIN`/`INT_MAX` values.
