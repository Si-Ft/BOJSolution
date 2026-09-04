import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T+1):
    N, M, L = map(int,input().split())
    tree = [0] * (N+3)
    for _ in range(M):
        n, v = map(int,input().split())
        tree[n] = v
    for i in range(N//2, L-1, -1):
        tree[i] += tree[i*2] + tree[i*2+1]
    print(f"#{tc} {tree[L]}")