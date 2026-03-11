# Flatten Binary Tree to Linked List

**Topic:** Binary Trees  
**Difficulty:** Medium  
**LeetCode URL:** https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

---

## Problem Statement

Given the `root` of a binary tree, flatten the tree into a **linked list in-place**.

The linked list should use the same `TreeNode` class where:
- The `right` child pointer points to the next node in the list
- The `left` child pointer is always `null`
- The linked list should be in the same order as a **pre-order traversal** of the binary tree

**Follow up:** Can you flatten the tree **in-place** (using O(1) extra space)?

---

## Examples

**Example 1:**
```
Input tree:
    1
   / \
  2   5
 / \   \
3   4   6

Output (as linked list via right pointers):
1 -> 2 -> 3 -> 4 -> 5 -> 6
(all left pointers are null)
```

**Example 2:**
```
Input:  root = []
Output: []
```

**Example 3:**
```
Input:  root = [0]
Output: [0]
```

---

## Constraints

- The number of nodes in the tree is in the range `[0, 2000]`
- `-100 <= Node.val <= 100`

---

## Approaches

### Approach 1: Recursive (Pre-order)
Flatten left and right subtrees recursively, then:
1. Store the right subtree
2. Move the flattened left subtree to the right
3. Append the stored right subtree at the end of the new right chain

**Time:** O(n) | **Space:** O(n) call stack

```python
def flatten(root):
    if not root:
        return
    flatten(root.left)
    flatten(root.right)

    left_tail = root.left
    if left_tail:
        while left_tail.right:
            left_tail = left_tail.right
        left_tail.right = root.right
        root.right = root.left
        root.left = None
```

---

### Approach 2: Morris Traversal — O(1) Space ✅ Optimal

For each node that has a **left child**:
1. Find the **rightmost node** of the left subtree (the predecessor)
2. Connect that rightmost node's `right` to the current node's `right`
3. Move the entire left subtree to the right
4. Set left to `null`
5. Move to `node.right` and repeat

```python
def flatten(root):
    curr = root
    while curr:
        if curr.left:
            # Find rightmost node of left subtree
            predecessor = curr.left
            while predecessor.right:
                predecessor = predecessor.right

            # Wire it up
            predecessor.right = curr.right
            curr.right = curr.left
            curr.left = None

        curr = curr.right
```

**Time:** O(n) | **Space:** O(1) ✅

---

## Walkthrough (Example 1)

```
Start:        curr = 1
Left exists:  find rightmost of [2->3, 2->4] => node 4
Wire:         4.right = 5->6
              1.right = 2
              1.left  = null
Tree now:     1->2->3, 2->4->5->6

Move curr=2, left exists, rightmost of [3] = 3
Wire:         3.right = 4->5->6
              2.right = 3
              2.left  = null

Continue until all left pointers are null
Final: 1->2->3->4->5->6
```

---

## Key Takeaways

- Pre-order traversal naturally gives the correct flattened order
- The Morris-style approach avoids recursion stack by rewiring pointers in-place
- Always identify the **predecessor** (rightmost of left subtree) — it's the bridge between left and right subtrees
