import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1,T+1):
    N, M = map(int, input().split())
    # (N+1)*(N+1) 배열 생성
    arr = [[0] * (N+1) for _ in range(N+1)]

    # 배열에 실제 값 대신 2차원 누적합 사용
    for i in range(1, N+1):
        row = list(map(int, input().split()))
        for j in range(1, N+1):
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + row[j-1]

    # (전체 범위) - (x기준 겹치는 범위 + y기준 겹치는 범위) + (x,y 둘다 겹치는 범위)
    ans = 0
    for y in range(1, N-M+2):
        for x in range(1, N-M+2):
            total = arr[y+M-1][x+M-1] - arr[y-1][x+M-1] - arr[y+M-1][x-1] + arr[y-1][x-1]
            if total > ans:
                ans = total

    print(f'#{tc} {ans}')
    
