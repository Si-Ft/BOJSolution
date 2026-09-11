import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    schedule = [list(map(int, input().split())) for _ in range(N)]

    # 스케줄이 시작 시간에 상관없이 빨리 끝날 수록 이후에 더 많은 일을 할 수 있는 여지가 있음.
    # 끝나는 시간을 기준으로 오름차순 정렬함. 같다면 시작 시간 기준으로 오름차순 정렬함. (스케줄 길이가 0일 수 있으므로)
    schedule.sort(key=lambda x: (x[1], x[0]))

    cnt = 0
    en_time = 0
    for st,en in schedule:
        if st >= en_time:
            cnt += 1
            en_time = en
    print(f'#{tc} {cnt}')