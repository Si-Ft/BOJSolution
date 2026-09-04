import sys
sys.stdin = open('input.txt', 'r')
for i in range(1, 11):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]

    # 1은 N극, 2는 S극 / 각 열 단위로 for문 -> 1은 아래서부터 2나올때까지 1 삭제, 2는 위에서부터 1나올때까지 2 삭제
    ans = 0
    for col in range(N):
        # 아래서부터 1 삭제
        for row in range(N-1, -1, -1):
            if arr[row][col] == 1:
                arr[row][col] = 0
            elif arr[row][col] == 2:
                break

        # 위에서부터 2 삭제
        for row in range(N):
            if arr[row][col] == 2:
                arr[row][col] = 0
            elif arr[row][col] == 1:
                break

        # 위에서부터 보면서 1->(0...0)->2 꼴의 교차점 개수 세기
        found_one = False
        for row in range(N):
            if arr[row][col] == 1:
                found_one = True
            elif arr[row][col] == 2 and found_one:
                ans += 1
                found_one = False

    print(f'#{i} {ans}')