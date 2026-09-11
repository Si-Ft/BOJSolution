import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, Q = map(int, input().split())

    # 서로소 집합 쓰기
    bumo = [i for i in range(N + 1)]
    rnk = [0 for _ in range(N + 1)]

    # 부모 노드 찾기 with 최적화
    def find(x):
        if bumo[x] != x:
            bumo[x] = find(bumo[x])
        return bumo[x]

    def union(x,y):
        a = find(x)
        b = find(y)
        if a != b:
            if rnk[a] < rnk[b]:
                a, b = b, a
            bumo[b] = a
            if rnk[a] == rnk[b]:
                rnk[a] += 1

    # 출력 최적화
    ans = '#'+str(tc)+' '
    for _ in range(Q):
        cmd, a, b = map(int, input().split())
        if cmd == 0:
            union(a, b)
            continue
        if find(a) == find(b):
            ans += '1'
        else:
            ans += '0'
    print(ans)