import sys
sys.stdin = open('input.txt', 'r')

class misang:
    def __init__(self, mid, y, x, cnt, d):
        self.mid = mid        # 미생물의 고유 ID
        self.y = y          # 미생물의 y좌표
        self.x = x          # 미생물의 x좌표
        self.cnt = cnt      # 미생물의 개체 수
        self.d = d          # 미생물의 이동 방향 (1: 상, 2: 하, 3: 좌, 4: 우)

# ID = mlist idx
mlist = []

# mlist id를 받아오면, 해당 위치에 마지막 미생물을 할당하고 pop (시간절약)
def del_mlist(msid):
    mlist[msid] = mlist[-1]
    mlist[msid].mid = msid
    mlist.pop()

T = int(input())
for tc in range(1, T+1):
    mlist = []
    dy = [0, -1, 1, 0, 0]
    dx = [0, 0, 0, -1, 1]
    rev = [0, 2, 1, 4, 3]       # 벽에 튕겼을 때 바뀌는 방향 미리 정의
    N, M, K = map(int, input().split())
    for i in range(K):
        y, x, cnt, d = map(int, input().split())
        mlist.append(misang(i, y, x, cnt, d))
    
    for st in range(M):
        tmpgrid = {}    # 미생물이 grid에 sparse하므로 dictionary로 관리
        midx = -1

        while midx < len(mlist)-1:
            midx += 1
            ms = mlist[midx]
            ms.y += dy[ms.d]
            ms.x += dx[ms.d]
            if ms.y == 0 or ms.y == N-1 or ms.x == 0 or ms.x == N-1:
                ms.cnt //= 2
                ms.d = rev[ms.d]  # 벽에 튕겼을 때 방향 변경
                if ms.cnt == 0:
                    del_mlist(ms.mid)
                    midx -= 1
                    continue  # 미생물이 사라졌으면 더 이상 처리하지 않음
            tmpgrid.setdefault((ms.y, ms.x), []).append(ms) # << 파이썬 진짜 뭐임?? 이거 왜됨??

        for y,x in tmpgrid:
            if len(tmpgrid[y,x]) > 1:
                # 가장 많은 군집을 맨 앞으로 오도록
                tmpgrid[y,x].sort(key=lambda ms: ms.cnt, reverse=True) 

                # 나머지는 본체에 추가 후 제거
                main = tmpgrid[y,x][0]  
                for ms in tmpgrid[y,x][1:]:
                    main.cnt += ms.cnt
                    del_mlist(ms.mid)

    ans = sum(ms.cnt for ms in mlist)
    print(f'#{tc} {ans}')
    