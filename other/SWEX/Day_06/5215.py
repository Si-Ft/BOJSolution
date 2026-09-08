import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, L = map(int, input().split())
    max_score = 0

    # 각 단계에서 idx만큼의 칼로리 소비 시 얻을 수 있는 최대 점수
    dp = [0] * (L + 1)

    for i in range(N):
        score, cal = map(int, input().split())

        # 출발선을 L로 함으로서 L을 넘는 경우는 고려X
        for j in range(L, cal - 1, -1):
            # 현재 칼로리 점수 vs 이전 칼로리 점수 + 현재 재료 점수 중 큰 값으로 갱신
            dp[j] = max(dp[j], dp[j - cal] + score)
    max_score = max(dp)
    print(f"#{tc} {max_score}")
