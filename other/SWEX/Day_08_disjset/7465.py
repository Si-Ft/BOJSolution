import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, M = map(int, input().split())

    # 서로소 집합 안 쓰고 풀어보기
    graph = [[] for _ in range(N + 1)]
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    # 모든 정점부터 시작해서 dfs가 실행되는 횟수 = 그룹의 개수
    visited = [False] * (N + 1)
    def dfs(cn):
        visited[cn] = True
        for nn in graph[cn]:
            if not visited[nn]:
                dfs(nn)
    
    ans = 0
    for i in range(1, N + 1):
        if not visited[i]:
            dfs(i)
            ans += 1
    print(f'#{tc} {ans}')
