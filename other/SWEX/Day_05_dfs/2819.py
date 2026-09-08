import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    grid = [list(input().split()) for _ in range(4)]
    result = set()

    dy = [-1,0,1,0]
    dx = [0,1,0,-1]
    def dfs(y, x, path):
        if len(path) == 7:
            result.add(path)
            return
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny<0 or ny>=4 or nx<0 or nx>=4:
                continue
            dfs(ny, nx, path + grid[ny][nx])

    for i in range(4):
        for j in range(4):
            dfs(i, j, grid[i][j])
    print(f'#{tc} {len(result)}')