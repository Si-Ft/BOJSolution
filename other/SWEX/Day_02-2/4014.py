import sys
sys.stdin = open('input.txt', 'r')

def can_construct(delta, x, n):
    # 순회하면서 -1,1인 곳만 감지해 조건 체크. (사용한 공간은 99로 체크)
    for i in range(1, n):
        # 불가능한 경우나 필요 없는경우 미리 처리
        if delta[i] == 0 or delta[i] == 99:
            continue
        if delta[i] < -1 or delta[i] > 1:
            return False

        # 오르막인 경우, i-1부터 i-x까지 경사로 체크
        if delta[i] == 1:
            if i-x < 0:                         # 경사로가 border 밖
                return False
            if delta[i-x] not in [-1,0,1]:        # 경사로 시작점은 -1, 0, 1 둘 다 가능
                return False
            if delta[i-x+1:i].count(0) != x-1:  # 경사로에 고차가 있거나, 이미 다른 경사로가 있는 경우
                return False
            for j in range(i-x, i):
                delta[j] = 99                   # 경사로 설치 완료 표시

        # 내리막인 경우
        if delta[i] == -1:
            if i+x-1 >= n:
                return False
            if delta[i:i+x].count(0) != x-1:
                return False
            for j in range(i+1, i+x):
                delta[j] = 99

    return True

T = int(input())
for tc in range(1,T+1):
    n,x = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]

    ans = 0
    for i in range(n):
        delta = [0]
        for j in range(1,n):
            delta.append(grid[i][j] - grid[i][j-1])
        if can_construct(delta, x, n):
            ans += 1

    for i in range(n):
        delta = [0]
        for j in range(1,n):
            delta.append(grid[j][i] - grid[j-1][i])
        if can_construct(delta, x, n):
            ans += 1

    print(f"#{tc} {ans}")