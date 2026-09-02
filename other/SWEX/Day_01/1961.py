import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1,T+1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    ans = [[''] * (3 * N + 2) for _ in range(N)]
    
    for sy in range(N):
        for sx in range(N):
            num = arr[sy][sx]
            ey0 = sx
            ex0 = N-1-sy
            ey1 = N-1-sy
            ex1 = N-1-sx
            ey2 = N-1-sx
            ex2 = sy
            
            ans[ey0][ex0] = str(num)
            ans[ey1][ex1+N+1] = str(num)
            ans[ey2][ex2+2*N+2] = str(num)
            ans[ey0][N] = ' '
            ans[ey0][2*N+1] = ' '
    
    print(f"#{tc}")
    for sy in range(N):
        print(''.join(ans[sy]))