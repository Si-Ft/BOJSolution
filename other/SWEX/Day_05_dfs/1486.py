import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for tc in range(1, T + 1):
    N, B = map(int, input().split())
    heights = list(map(int, input().split()))
    min_gap = 999999

    for i in range(1 << N):
        total = 0
        for j in range(N):
            if i & (1 << j):
                total += heights[j]
        if total >= B:
            min_gap = min(min_gap, total - B)
    
    print(f'#{tc} {min_gap}')