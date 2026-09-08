import sys
sys.stdin = open('input.txt', 'r')

from collections import deque

for tc in range(1, 11):
    _ = input()
    grid = [list(map(int, input().strip())) for _ in range(16)]
    dist = [[0] * 16 for _ in range(16)]
    dy=[-1,0,1,0]
    dx=[0,1,0,-1]

    st = None
    en = None
    for y in range(16):
        for x in range(16):
            if grid[y][x] == 2:
                st = (y, x)
            elif grid[y][x] == 3:
                en = (y, x)

    q = deque([st])
    dist[st[0]][st[1]] = 1
    while q:
        cy, cx = q.popleft()
        if (cy, cx) == en:
            break
        for d in range(4):
            ny, nx = cy + dy[d], cx + dx[d]
            if ny<0 or ny>=16 or nx<0 or nx>=16:    # 범위 밖
                continue
            if grid[ny][nx] == 1:                   # 벽 위치
                continue
            if dist[ny][nx] != 0:                   # 이미 방문한 위치
                continue
            dist[ny][nx] = dist[cy][cx] + 1
            q.append((ny, nx))

    print(f"#{tc} {1 if dist[en[0]][en[1]] else 0}")