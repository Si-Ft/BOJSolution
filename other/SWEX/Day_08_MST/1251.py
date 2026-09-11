import sys
sys.stdin = open('input.txt', 'r')

import heapq
TC = int(input())
for tc in range(1, TC + 1):
    N = int(input())

    x_coords = list(map(int, input().split()))
    y_coords = list(map(int, input().split()))
    E = float(input())

    # 프림 알고리즘
    visited = [False] * N
    pq = [(0, 0)]       # 거리 제곱, 섬 번호

    tot_dist = 0
    cnt = 0

    while pq:
        dist_sq, u = heapq.heappop(pq)

        # 이미 방문한 섬이라면 스킵
        if visited[u]:
            continue

        # 방문 처리 및 가중치 합산
        visited[u] = True
        tot_dist += dist_sq
        cnt += 1

        # 모든 섬이 연결되면 종료
        if cnt == N:
            break

        # 현재 섬에서 방문하지 않은 다른 섬까지의 거리 계산 후 pq에 추가
        for v in range(N):
            if not visited[v]:
                cost = (x_coords[u] - x_coords[v]) ** 2 + (y_coords[u] - y_coords[v]) ** 2
                heapq.heappush(pq, (cost, v))

    # 최종 환경 부담금 계산
    ans = E * tot_dist
    print(f"#{tc} {ans:.0f}")