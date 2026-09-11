import sys
sys.stdin = open('input.txt', 'r')

from collections import deque
TC = int(input())
for tc in range(1, TC + 1):
    # 거지같은 입력 파싱하기
    inp = list(map(int, input().split()))
    N = inp[0]

    # 인접 리스트로 만들기
    v = [[]*N for _ in range(N)]
    for y in range(N):
        for x in range(N):
            idx = y*N+x+1
            if inp[idx] >= 1:
                v[y].append(x)

    ans = 9999

    # 현재 위치부터 bfs 탐색
    def bfs(st):
        dist = [9999]*N
        dist[st] = 0
        csum = 0
        q = deque([st])
        while q:
            cur = q.popleft()
            for nxt in v[cur]:
                if dist[nxt] == 9999:
                    dist[nxt] = dist[cur] + 1
                    csum += dist[nxt]

                    # 정답 가망이 없는 경우, 가지치기 (10배 이상 빨라짐)
                    if csum >= ans:
                        return csum
                    q.append(nxt)
        return csum

    # 냅다 모든 노드에서 bfs 돌려버림
    for i in range(N):
        ans = min(ans, bfs(i))
    print(f'#{tc} {ans}')