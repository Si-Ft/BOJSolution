import sys
sys.stdin = open('input.txt', 'r')

MAX_VALUE = 9999
TC = int(input())
for tc in range(1, TC + 1):
    inp = list(map(int, input().split()))
    N = inp[0]
    matrix = []
    for i in range(N):
        matrix.append(inp[i*N+1:(i+1)*N+1])

    # 연결되지 않은 간선은 무한대로 지정
    for i in range(N):
        for j in range(N):
            if i != j and matrix[i][j] == 0:
                matrix[i][j] = MAX_VALUE

    # 플로이드 워셜 알고리즘 사용 (모든 거리가 필요하므로)
    for via in range(N):
        for st in range(N):
            if matrix[st][via] == MAX_VALUE:
                continue

            for en in range(N):
                if matrix[via][en] == MAX_VALUE:
                    continue
                matrix[st][en] = min(matrix[st][en], matrix[st][via] + matrix[via][en])

    ans = MAX_VALUE
    for i in range(N):
        ans = min(ans, sum(matrix[i]))

    # for i in range(N):
    #     assert matrix[i][i] == 0, "음수 사이클 존재"
    print(f'#{tc} {ans}')