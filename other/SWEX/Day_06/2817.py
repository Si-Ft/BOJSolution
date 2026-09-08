# 비효율적이지만 직관적인 방법
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, K = map(int, input().split())
    numbers = list(map(int, input().split()))
    ans = 0
    for i in range(1, 1<<N):
        # 위치에 맞는 숫자만 합을 구함
        s=0
        for j in range(N):
            if i & (1<<j):
                s += numbers[j]
        if s==K:
            ans += 1
    print(f"#{tc} {ans}")