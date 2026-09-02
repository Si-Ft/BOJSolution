import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1,T+1):
    N = int(input())
    # 미리 10*10 그리드 만들어놓기
    grid = [[0]*10 for _ in range(10)]

    for _ in range(N):
        x1, y1, x2, y2, color = map(int, input().split())
        for i in range(x1, x2+1):
            for j in range(y1, y2+1):
                # 빨강비트 : 01, 파랑비트 : 10 => 겹친 보라색 비트 : 11(3)
                grid[i][j] |= color

    result = 0
    for i in range(10):
        for j in range(10):
            if grid[i][j] == 3:
                result += 1

    print(f'#{tc} {result}')