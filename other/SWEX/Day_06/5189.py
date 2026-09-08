import sys
sys.stdin = open('input.txt', 'r')

# 그래프크기, 그래프, 최소비용
N, graph, m = None, None, None

# 정점 방문 수, 이전 정점, 현재비용, 방문상태
def dfs(v, before, cost, visited):
    global N, graph, m
    if cost >= m:         # 불가능분기 가지치기
        return
    if v == N:              # 모든 정점 방문
        cost += graph[before][0]   # 출발지 복귀
        m = min(m, cost)
        return
    for i in range(1, N):   # 다음 방문할 정점 선택
        if not (visited & (1 << i)):
            visited += (1 << i)
            dfs(v+1, i, cost + graph[before][i], visited)
            visited -= (1 << i)

# 임시 초기값을 구하는 함수
def greedy_initial_m():
    global N, graph
    visited = 1
    cur_m = 0
    i = 0
    while visited != (1 << N) - 1:
        nxt = [(graph[i][j], j) for j in range(1, N) if not (visited & (1 << j))]
        nxt.sort()
        cost, i = nxt[0]
        visited += (1 << i)
        cur_m += cost
    return cur_m + graph[i][0]

T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    graph = [list(map(int, input().split())) for _ in range(N)]

    # 선택 : 초기 m값을 간단한 그리디로 적당히 작은 값 설정
    # 매 순간 가장 가까운 정점을 선택하여 초기 m값 설정
    # N값이 클 수록 그리디 초기값이 더 중요해짐
    m = 9999
    m = greedy_initial_m()

    visited = 1
    dfs(1, 0, 0, visited)
    print(f"#{tc} {m}")
