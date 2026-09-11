import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, M = map(int, input().split())

    # 컨테이너, 트럭 내림차순 정렬, 큰 컨테이너부터 큰 트럭에 실음
    cont = list(map(int, input().split()))
    truck = list(map(int, input().split()))
    cont.sort(reverse=True)
    truck.sort(reverse=True)

    truck_ptr = 0
    tot = 0
    for c in cont:
        # 모든 트럭 사용 시 종료
        if truck_ptr >= M:
            break
        # 현재 컨테이너를 현재 트럭이 실을 수 있는지 확인
        if c <= truck[truck_ptr]:
            tot += c
            truck_ptr += 1
            
    print(f'#{tc} {tot}')
