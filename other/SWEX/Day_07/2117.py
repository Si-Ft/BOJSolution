import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, M = map(int, input().split())
    house = []      # 집의 좌표만 저장함
    cost = [i*i + (i-1)*(i-1) for i in range(2*N)]     # 운영 영역 크기에 따른 비용 사전 계산

    for y in range(N):
        row = list(map(int, input().split()))
        for x in range(N):
            if row[x] == 1:
                house.append((y, x))

    max_house = 0
    # ty, tx : 운영 영역 중심 좌표
    for ty in range(N):
        for tx in range(N):
            # idx : ty,tx와의 거리, value : 해당 거리 내에 있는 집의 수
            house_dists = [0] * (2*N)
            for hy, hx in house:
                dist = abs(ty - hy) + abs(tx - hx)
                # dist 이상 크기의 운영 영역에 집이 있으므로 집 수 일괄 계산
                house_dists[dist+1:] = [x+1 for x in house_dists[dist+1:]]

            for k in range(2*N-1, 0, -1):
                if house_dists[k] * M >= cost[k]:
                    max_house = max(max_house, house_dists[k])
                    break

    print(f'#{tc} {max_house}')
