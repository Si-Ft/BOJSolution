import sys
sys.stdin = open('input.txt', 'r')

import heapq

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    grid = [list(map(int, input().strip())) for _ in range(N)]
    dist = [[-1]*N for _ in range(N)]

    q = []          # 우선순위 큐 정의
    heapq.heappush(q, (0, 0, 0))
    dist[0][0] = 0
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    # 최적 거리가 보장된 최소거리 위치부터 탐색
    while q:
        w,cy,cx = heapq.heappop(q)

        # 목적지 도착 처리
        if cy == N-1 and cx == N-1:
            print(f'#{tc} {w}')
            break

        for d in range(4):
            ny = cy+dy[d]
            nx = cx+dx[d]
            if ny < 0 or ny >= N or nx < 0 or nx >= N:
                continue        # 범위 밖
            if dist[ny][nx] != -1:
                continue        # 이미 방문한 곳
            # 현재 위치는 최적 거리이므로, 주변 전부 최소거리 갱신
            dist[ny][nx] = w + grid[ny][nx]
            heapq.heappush(q, (dist[ny][nx], ny, nx))
