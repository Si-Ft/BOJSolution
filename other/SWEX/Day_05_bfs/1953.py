import sys
sys.stdin = open('input.txt', 'r')

from collections import deque
# 각 방향 별 dy, dx 쿼리와 이동 가능한 파이프 타입
can_go = [
    (-1, 0, [1,2,5,6]),         # 상
    (1, 0, [1,2,4,7]),          # 하
    (0, -1, [1,3,4,5]),         # 좌
    (0, 1, [1,3,6,7])           # 우
]
# 현재 위치 파이프 별 이동 가능한 방향
dfs_query=[
    [],
    [0,1,2,3],      # 1 | 상하좌우
    [0,1],          # 2 | 상하
    [2,3],          # 3 | 좌우
    [0,3],          # 4 | 상우
    [1,3],          # 5 | 하우
    [1,2],          # 6 | 하좌
    [0,2]           # 7 | 상좌
]

T = int(input())
for tc in range(1, T+1):
    N,M,sy,sx,time=map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]

    # 최소 시간 1일 때는 시작 위치만 가능
    if time==1:
        print(f'#{tc} 1')
        continue

    dist = [[0]*M for _ in range(N)]
    q = deque()
    q.append((sy, sx))
    dist[sy][sx] = 1
    cnt = 1

    while q:
        cy, cx = q.popleft()
        # 현재 파이프의 연결 방향만 탐색함
        for cdir in dfs_query[grid[cy][cx]]:
            dy, dx, valid_types = can_go[cdir]
            ny, nx = cy + dy, cx + dx
            if ny<0 or ny>=N or nx<0 or nx>=M:
                continue        # 범위 벗어남
            if dist[ny][nx] != 0:
                continue        # 이미 방문함
            if grid[ny][nx] not in valid_types:
                continue        # 이동 불가 파이프
            dist[ny][nx] = dist[cy][cx] + 1
            cnt += 1

            # 아직 더 갈 수 있는 시간이 있다면 더 이동
            if dist[ny][nx] < time:
                q.append((ny, nx))

    print(f'#{tc} {cnt}')