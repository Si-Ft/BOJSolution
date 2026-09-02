T = int(input())
for tc in range(1, T+1):
    N = int(input())
    grid = [list(input().strip()) for _ in range(N)]

    ans = 0
    mid = N // 2
    for y in range(N):
        for x in range(N):
            dist = abs(mid - y) + abs(mid - x)
            if dist > mid:
                continue
            ans += int(grid[y][x])

    print(f'#{tc} {ans}')