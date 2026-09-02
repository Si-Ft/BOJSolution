import sys
sys.stdin = open('input.txt', 'r')
for tc in range(1,11):
    tc_num = int(input())
    grid = [list(map(int, input().split())) for _ in range(100)]

    sero = []           # 사다리의 세로선 위치 좌표
    cur = -1            # sero 기준 현재 위치
    for j in range(100):
        if grid[0][j] == 0:
            continue
        sero.append(j)
        if grid[99][j] == 2:
            cur = sero.index(j)

    for i in range(99, -1, -1):
        # 현재 위치의 세로선에서 바로 좌우의 가로선이 있는지만 확인
        if cur > 0 and grid[i][sero[cur]-1] == 1:
            cur -= 1
        elif cur < len(sero)-1 and grid[i][sero[cur]+1] == 1:
            cur += 1

    print(f'#{tc} {sero[cur]}')