# Serialize and Deserialize Binary Tree

**Topic:** Trees / BFS  
**Difficulty:** Hard  
**LeetCode Link:** https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

---

## Problem Statement

Design an algorithm to **serialize** and **deserialize** a binary tree.

- **Serialize:** Convert a binary tree to a single string.
- **Deserialize:** Reconstruct the original binary tree from that string.

There is no restriction on how you perform serialization/deserialization — just ensure that a tree can be serialized to a string and that string can be deserialized back to the original tree structure.

**Example:**
```
Input tree:
    1
   / \
  2   3
     / \
    4   5

serialize(root) -> "1,2,null,null,3,4,null,null,5,null,null"
deserialize("1,2,null,null,3,4,null,null,5,null,null") -> original tree
```

---

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`

---

## Approach: BFS (Level-Order)

### Intuition
Use level-order traversal (BFS) to serialize the tree layer by layer, marking missing children as `"null"`. For deserialization, replay the BFS using a queue, assigning children to each node in order.

### Serialize Steps
1. Use a queue starting with root.
2. For each node, append its value (or `"null"`) to the result.
3. If the node is not null, enqueue its left and right children.

### Deserialize Steps
1. Split the string by delimiter.
2. Create the root from the first token.
3. Use a queue of nodes; for each node, assign the next two tokens as left and right children.

---

## Solution (Python)

```python
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string using BFS."""
        if not root:
            return ""

        result = []
        queue = deque([root])

        while queue:
            node = queue.popleft()
            if node is None:
                result.append("null")
            else:
                result.append(str(node.val))
                queue.append(node.left)   # enqueue even if None
                queue.append(node.right)

        return ",".join(result)

    def deserialize(self, data: str) -> TreeNode:
        """Decodes a string to a binary tree using BFS."""
        if not data:
            return None

        tokens = data.split(",")
        root = TreeNode(int(tokens[0]))
        queue = deque([root])
        i = 1  # index into tokens

        while queue and i < len(tokens):
            node = queue.popleft()

            # Assign left child
            if tokens[i] != "null":
                node.left = TreeNode(int(tokens[i]))
                queue.append(node.left)
            i += 1

            # Assign right child
            if i < len(tokens) and tokens[i] != "null":
                node.right = TreeNode(int(tokens[i]))
                queue.append(node.right)
            i += 1

        return root
```

---

## Complexity Analysis

| | Serialize | Deserialize |
|---|---|---|
| **Time** | O(N) | O(N) |
| **Space** | O(N) | O(N) |

Where **N** is the number of nodes in the tree.

---

## Key Interview Talking Points

1. **Why BFS over DFS?**  
   BFS naturally handles `null` children without needing two null markers per leaf, making the serialized string slightly more compact and intuitive.

2. **Alternative: Preorder DFS**  
   DFS (preorder) works too — serialize left subtree then right subtree recursively, mark nulls. It's equally valid.

3. **Edge cases to mention:**
   - Empty tree → return empty string
   - Single node → `"5,null,null"`
   - Skewed tree (all left or all right children)

4. **Interviewer follow-up:** "Can you do it without extra space?" — Not easily; the queue/stack is inherent to tree traversal.
