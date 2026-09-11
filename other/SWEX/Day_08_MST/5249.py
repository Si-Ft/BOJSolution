# 정석적인 MST_크루스칼 알고리즘
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, M = map(int, input().split())
    edges = []
    bumo = [i for i in range(N + 1)]
    def find(x):
        if bumo[x] != x:
            bumo[x] = find(bumo[x])
        return bumo[x]

    def union(x, y):
        a = find(x)
        b = find(y)
        if a != b:
            bumo[b] = a 

    for i in range(M):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))

    # 간선의 가중치를 기준으로 작은 것부터 봄
    edges.sort(key=lambda x: x[2])
    result = 0
    for u, v, w in edges:
        if find(u) != find(v):
            union(u, v)
            result += w
    print(f'#{tc} {result}')