import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1,T+1):
    N, K = map(int, input().split())
    
    kwindow = (1 << (K + 1)) - 2
    owindow = (1 << (K + 2)) - 1
    
    garo = [0] * N
    sero = [0] * N
    
    # 비트 생성
    for y in range(N):
        data = list(map(int, input().split()))
        for x in range(N):
            tmp = int(data[x])
            garo[y] |= (tmp << (x + 1))
            sero[x] |= (tmp << (y + 1))
    
    ans = 0
    
    # 가로, 세로 비트 검사
    for i in range(N):
        val_g = garo[i]
        while val_g:
            if (val_g & owindow) == kwindow:
                ans += 1
            val_g >>= 1
            
        val_s = sero[i]
        while val_s:
            if (val_s & owindow) == kwindow:
                ans += 1
            val_s >>= 1
            
    print(f"#{tc} {ans}")