import sys
input = sys.stdin.readline
# 2606.py
V = int(input())
E = int(input())
adj = [[] for _ in range(V + 1)]
for _ in range(E):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
# DFS
stack = [1]
visited = [1]
while stack:
    cur = stack.pop()
    for to in adj[cur]:
        if to not in visited:
            stack.append(to)
            visited.append(to)
print(len(visited) - 1)