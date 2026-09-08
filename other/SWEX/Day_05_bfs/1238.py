import sys
sys.stdin = open('input.txt', 'r')

from collections import deque

for tc in range(1, 11):
    N, start = map(int, input().split())
    arr = list(map(int,input().split()))
    v = [[] for _ in range(101)]
    for i in range(0, len(arr), 2):
        v[arr[i]].append(arr[i+1])

    visited = [False] * 101
    epoch = []
    q = deque()
    q.append(start)
    q.append(-1)
    visited[start] = True

    while q:
        cp = q.popleft()    # 현재 연락망을 돌릴 사람

        # 단위가 끝났음을 체크
        if cp == -1:
            if not q:
                break
            q.append(-1)
            epoch.clear()
            continue

        # 현재 단위에서 연락망에 닿은 사람들
        epoch.append(cp)
        for nxt in v[cp]:
            # 근처 연락망의 사람들
            if not visited[nxt]:
                visited[nxt] = True
                q.append(nxt)

    print(f"#{tc} {max(epoch)}")
