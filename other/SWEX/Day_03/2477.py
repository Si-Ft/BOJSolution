import sys
sys.stdin = open('input.txt', 'r')
T=int(input())
for tc in range(1, T+1):
    cA, cB, k, fA, fB= map(int, input().split())
    listA = list(map(int, input().split()))     # cA개
    endA = [0] * cA                             # A 창구의 점유 종료 시각
    listB = list(map(int, input().split()))     # cB개
    endB = [0] * cB                             # B 창구의 점유 종료 시각
    custA = list(map(int, input().split()))     # k개
    custB = []                                  # A 창구 이용 후 B 창구 대기 큐(고객 번호, 도착 시간)
    fAcust = []                                 # A 창구의 fA번 창구 이용한 고객 목록
    fBcust = []                                 # B 창구의 fB번 창구 이용한 고객 목록

    # A 창구 배정 후 점유 시간 계산
    for cnum in range(1, k+1):
        stime = custA[cnum-1]

        # 빈 창구가 있을 경우 (endA[i] <= stime) 바로 배정
        # 없다면 가장 빨리 끝나는 창구에 배정
        mingap = 9999
        assignA = -1
        for i in range(cA):
            if endA[i] <= stime:
                assignA = i
                break
            elif endA[i] < mingap:
                mingap = endA[i]
                assignA = i

        # 배정 후 점유 시간 갱신
        endA[assignA] = max(endA[assignA], stime) + listA[assignA]
        if assignA == fA-1:
            fAcust.append(cnum)
        custB.append((cnum, endA[assignA], assignA))

    # 도착시간 순서대로 정렬. 같다면 창구번호가 작은 고객 우선
    custB.sort(key=lambda x: (x[1], x[2]))
    # print(custB)

    # 동일하게 B창구도 배정 후 계산
    for cnum, stime, assignA in custB:
        mingap = 9999
        assignB = -1
        for i in range(cB):
            if endB[i] <= stime:
                assignB = i
                break
            elif endB[i] < mingap:
                mingap = endB[i]
                assignB = i

        endB[assignB] = max(endB[assignB], stime) + listB[assignB]
        if assignB == fB-1:
            fBcust.append(cnum)

    # print(fAcust)
    # print(fBcust)

    # fA, fB 창구를 동시에 이용한 고객의 합을 찾기
    both = set(fAcust) & set(fBcust)
    print(f'#{tc} {sum(both) if both else -1}')