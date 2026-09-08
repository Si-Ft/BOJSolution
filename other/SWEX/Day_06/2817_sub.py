# 효율적인 방법 (부분합 DP)
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, K = map(int, input().split())
    numbers = list(map(int, input().split()))
    dp = [0] * (K+1)    # value : idx 값을 만들 수 있는 경우의 수
    dp[0] = 1           # 수 선택하지 않을 시 경우의 수
    for num in numbers:
        # 역순으로 순회하여 이전 상태에 독립적으로 수행함.
        for i in range(K, num-1, -1):
            dp[i] += dp[i-num]
    print(f"#{tc} {dp[K]}")