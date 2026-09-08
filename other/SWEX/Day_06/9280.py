import sys
sys.stdin = open('input.txt', 'r')

from collections import deque
import heapq
T = int(input())
for tc in range(1, T + 1):
    # ========== 입력부 ==========
    # 주차장 크기, 차량 수
    N, M = map(int, input().split())
    # 주차 무게 당 요금 정보(1번부터), 차의 무게 정보 (최종 요금 fees*carw)
    fees = [0] + [int(input()) for _ in range(N)]
    carw = [0] + [int(input()) for _ in range(M)]
    # 차량 입출차 쿼리
    inout = [int(input()) for _ in range(2*M)]

    # ========== 변수 선언부 ==========
    # 주차장 상태 stack (주차장의 빈 공간), heapq로 관리
    parking = [i for i in range(1,N+1)]
    heapq.heapify(parking)
    # 들어가지 못하고 대기중인 차량 큐
    carq = deque()
    # 각 차별 주차한 위치 (퇴장 시 해당 value는 최종 요금으로 대체)
    carpos = [0] * (M + 1)

    for Q in inout:
        if Q > 0:
            if parking:
                # 빈 주차장이 있으므로 할당
                carpos[Q] = heapq.heappop(parking)
            else:
                # 빈 주차장이 없으므로 대기 큐에 추가
                carq.append(Q)
        else:
            Q = -Q
            totfee = fees[carpos[Q]] * carw[Q]
            heapq.heappush(parking, carpos[Q])
            carpos[Q] = totfee
            
            # 대기 중인 차량이 있으면 주차
            if carq:
                next_car = carq.popleft()
                carpos[next_car] = heapq.heappop(parking)

    print(f'#{tc} {sum(carpos)}')
