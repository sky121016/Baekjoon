from collections import deque

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    
    visited = [[False] * m for _ in range(n)]
    dist = [[-1] * m for _ in range(n)]
    
    q = deque()
    visited[0][0] = True
    dist[0][0] = 1
    q.append((0, 0))
    
    dir = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    
    
    while q:
        vy, vx = q.popleft()
        
        if vy == n and vx == m:
            break
        
        for i in range(4):
            ny = vy + dir[i][0]
            nx = vx + dir[i][1]
            
            if 0<=ny<n and 0<=nx<m and not visited[ny][nx] and maps[ny][nx] == 1:
                visited[ny][nx] = True
                dist[ny][nx] = dist[vy][vx]+1
                q.append((ny, nx))
                
    
    
    answer = dist[n-1][m-1]
    
    
    return answer