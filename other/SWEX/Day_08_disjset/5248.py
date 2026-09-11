import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, M = map(int, input().split())

    # 서로소 집합 쓰기
    bumo = [i for i in range(N + 1)]
    pairs = list(map(int, input().split()))

    # 부모 노드 찾기 with 최적화
    def find(x):
        if bumo[x] != x:
            bumo[x] = find(bumo[x])
        return bumo[x]

    def union(x,y):
        a = find(x)
        b = find(y)
        if a != b:
            bumo[b] = a

    for i in range(M):
        a, b = pairs[2*i], pairs[2*i+1]
        union(a, b)

    ans = 0
    for i in range(1, N + 1):
        if bumo[i] == i:
            ans += 1
    print(f'#{tc} {ans}')
