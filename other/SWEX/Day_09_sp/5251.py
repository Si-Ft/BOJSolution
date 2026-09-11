import sys
sys.stdin = open('input.txt', 'r')

import heapq
TC = int(input())
for tc in range(1, TC + 1):
    N, E = map(int, input().split())
    v = [[9999] * (N+1) for _ in range(N+1)]
    for _ in range(E):
        # 간선이 매우 많으므로, 필요없는 간선 사전 삭제
        a, b, w = map(int, input().split())
        if a!=b:
            v[a][b] = min(v[a][b], w)

    
    dist = [9999] * (N+1)
    def dijk(st):
        visited = [False] * (N+1)
        dist[st] = 0
        heap = [(0, st)]     # 다음에 방문할 곳
        while heap:
            d, node = heapq.heappop(heap)
            if visited[node]:
                continue
            visited[node] = True
            for i in range(1, N+1):
                if not visited[i] and v[node][i] != 9999 and dist[i] > d + v[node][i]:
                    dist[i] = d + v[node][i]
                    heapq.heappush(heap, (dist[i], i))

    dijk(0)
    print(f"#{tc} {dist[N]}")