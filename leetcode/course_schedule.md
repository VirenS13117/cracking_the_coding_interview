# Course Schedule

**Topic:** Graph / Topological Sort  
**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/course-schedule/

---

## Problem Statement

There are `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`.  
You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

Return `true` if you can finish all courses. Otherwise, return `false`.

---

## Examples

**Example 1:**
```
Input:  numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: Take course 0 first, then course 1.
```

**Example 2:**
```
Input:  numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: Cycle detected — impossible to finish both courses.
```

---

## Constraints

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- All pairs `prerequisites[i]` are **unique**.

---

## Approach: Cycle Detection via DFS (or BFS / Kahn's Algorithm)

### Key Insight
The problem reduces to: **Does the directed graph of prerequisites contain a cycle?**
- If yes → `false` (impossible to finish all courses)
- If no  → `true`

---

### Approach 1 — DFS with Coloring

Use three states for each node:
- `0` = unvisited
- `1` = visiting (currently in the DFS call stack → cycle if revisited)
- `2` = visited (fully processed, safe)

```python
def canFinish(numCourses: int, prerequisites: list[list[int]]) -> bool:
    graph = [[] for _ in range(numCourses)]
    for course, pre in prerequisites:
        graph[pre].append(course)

    state = [0] * numCourses  # 0=unvisited, 1=visiting, 2=visited

    def dfs(node):
        if state[node] == 1:  # cycle detected
            return False
        if state[node] == 2:  # already verified safe
            return True

        state[node] = 1       # mark as visiting
        for neighbor in graph[node]:
            if not dfs(neighbor):
                return False
        state[node] = 2       # mark as fully visited
        return True

    for course in range(numCourses):
        if not dfs(course):
            return False
    return True
```

**Time:** O(V + E)  
**Space:** O(V + E)

---

### Approach 2 — BFS / Kahn's Algorithm (Topological Sort)

1. Compute **in-degree** of every node.
2. Enqueue all nodes with in-degree `0`.
3. Process queue: for each node, reduce neighbors' in-degrees; enqueue any that hit `0`.
4. If total processed nodes == `numCourses` → no cycle → `true`.

```python
from collections import deque

def canFinish(numCourses: int, prerequisites: list[list[int]]) -> bool:
    graph = [[] for _ in range(numCourses)]
    in_degree = [0] * numCourses

    for course, pre in prerequisites:
        graph[pre].append(course)
        in_degree[course] += 1

    queue = deque(i for i in range(numCourses) if in_degree[i] == 0)
    processed = 0

    while queue:
        node = queue.popleft()
        processed += 1
        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    return processed == numCourses
```

**Time:** O(V + E)  
**Space:** O(V + E)

---

## Common Pitfalls

- Forgetting to handle **disconnected graphs** — always iterate over all nodes.
- Confusing edge direction: `[a, b]` means `b → a` (b is prerequisite of a).
- Using a simple `visited` boolean instead of the **3-state** coloring in DFS, which misses back-edge detection.

---

## Summary Table

| Approach | Time | Space | Notes |
|---|---|---|---|
| DFS (3-color) | O(V+E) | O(V+E) | Intuitive cycle detection |
| BFS / Kahn's | O(V+E) | O(V+E) | Iterative, avoids recursion stack |
