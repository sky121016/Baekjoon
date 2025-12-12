from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

adj = [[] for _ in range (n+1)]
visited = [False] * (n+1)

for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

q = deque()


def bfs():
    while q:
        cur = q.popleft()

        for i in range(len(adj[cur])):
            next = adj[cur][i]

            if not visited[next]:
                visited[next] = True
                q.append(next)


cnt = 0
for i in range(1, n+1):
    if not visited[i]:
        cnt += 1
        q.append(i)
        bfs()

print(cnt)
