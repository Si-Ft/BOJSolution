import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T+1):
    r,c = map(int, input().split())
    grid = [list(map(int, input().strip())) for _ in range(r)]

    sr = 0
    sc = 0
    for i in range(r):
        if (1 in grid[i]):
            sr = i
            sc = len(grid[i]) - 1 - grid[i][::-1].index(1)
            break

    barcode = grid[sr][sc-55:sc+1]
    bardict = [[0,0,0,1,1,0,1],     # 0
               [0,0,1,1,0,0,1],     # 1
               [0,0,1,0,0,1,1],     # 2
               [0,1,1,1,1,0,1],     # 3
               [0,1,0,0,0,1,1],     # 4
               [0,1,1,0,0,0,1],     # 5
               [0,1,0,1,1,1,1],     # 6
               [0,1,1,1,0,1,1],     # 7
               [0,1,1,0,1,1,1],     # 8
               [0,0,0,1,0,1,1]]     # 9

    chksum = 0
    puresum = 0
    for i in range(0,56,7):
        mul = 3 if (i//7) % 2 == 0 else 1
        segment = barcode[i:i+7]
        for j in range(10):
            if segment == bardict[j]:
                chksum += j * mul
                puresum += j
                break

    if chksum % 10 == 0:
        print(f'#{tc} {puresum}')
    else:
        print(f'#{tc} 0')
    