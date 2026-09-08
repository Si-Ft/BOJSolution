import sys
sys.stdin = open('input.txt', 'r')

# 선택한 지역의 꿀의 최대 수익 미리 계산
def find_max_profit(sel_honey, C):
    n = len(sel_honey)
    max_profit = 0
    for i in range(1 << n):
        total_honey = 0
        profit = 0
        for j in range(n):
            if i & (1 << j):
                total_honey += sel_honey[j]
                profit += sel_honey[j] ** 2
        if total_honey <= C:
            max_profit = max(max_profit, profit)
    return max_profit

T = int(input())
for tc in range(1, T + 1):
    N, M, C = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]
    pre_cal = [[0] * (N - M + 1) for _ in range(N)]

    for i in range(N):
        for j in range(N - M + 1):
            pre_cal[i][j] = find_max_profit(grid[i][j:j+M], C)

    # 두 구역을 선택할 수 있는 모든 경우 순회
    max_sum_profit = 0

    # 동일한 행에서 선택하는 경우
    for y in range(N):
        for x1 in range(N - M + 1):
            for x2 in range(x1 + M, N - M + 1):
                max_sum_profit = max(max_sum_profit, pre_cal[y][x1] + pre_cal[y][x2])

    # 다른 행에서 선택하는 경우
    for y1 in range(N):
        for x1 in range(N - M + 1):
            for y2 in range(y1 + 1, N):
                for x2 in range(N - M + 1):
                    max_sum_profit = max(max_sum_profit, pre_cal[y1][x1] + pre_cal[y2][x2])

    print(f'#{tc} {max_sum_profit}')
