import sys
sys.stdin = open('input.txt', 'r')

from collections import deque
N, W, H, ans = 0, 0, 0, 0

def break_block(grid, depth):
    global N, W, H, ans
    if depth == N:
        cnt = 0
        for i in range(H):
            for j in range(W):
                if grid[i][j] > 0:
                    cnt += 1
        ans = min(ans, cnt)
        return
    
    for i in range(W):
        # 백트래킹을 위해 상태 복사 후 시뮬레이션 진행
        new_grid = [row[:] for row in grid]
        break_simul(new_grid, i)
        order_simul(new_grid)
        break_block(new_grid, depth + 1)

# grid의 X좌표에 구슬을 떨궜을 때, 블럭을 파괴하는 시뮬레이션
def break_simul(grid, x):
    global N, W, H, ans
    y = 0
    while y < H and grid[y][x] == 0:
        y += 1
    if y == H:
        return
    q = deque()
    q.append((y, x))    # 최초로 맞는 블럭의 좌표

    while q:
        cy, cx = q.popleft()
        rang = grid[cy][cx]
        grid[cy][cx] = 0
        for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            for d in range(1, rang):
                ny, nx = cy + dy * d, cx + dx * d
                if 0 <= ny < H and 0 <= nx < W and grid[ny][nx] > 0:
                    q.append((ny, nx))

# 블록들을 아래로 내리는 시뮬레이
def order_simul(grid):
    global N, W, H, ans
    for x in range(W):
        empty_row = H-1
        for y in range(H-1, -1, -1):
            if grid[y][x] > 0:
                if y != empty_row:
                    grid[empty_row][x] = grid[y][x]
                    grid[y][x] = 0
                empty_row -= 1

T = int(input())
for tc in range(1, T + 1):
    N, W, H = map(int, input().split())
    ans = 9999
    grid = [list(map(int, input().split())) for _ in range(H)]
    break_block(grid, 0)
    print(f'#{tc} {ans}')