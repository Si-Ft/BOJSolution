import sys
sys.stdin = open('input.txt', 'r')

N = 0
probs = []
max_prob = 0.0
def dfs(depth, cur_prob, visited):
    global N, max_prob, probs

    # 가능성이 없는 분기 제거
    if cur_prob <= max_prob:
        return

    # 모든 깊이 탐색 시 확률 갱신 
    if depth == N:
        max_prob = cur_prob
        return

    for i in range(N):
        if visited & (1<<i):
            continue
        dfs(depth + 1, cur_prob * (probs[depth][i]/100), visited|(1<<i))
    
T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    probs = [list(map(float, input().split())) for _ in range(N)]
    max_prob = 0.0
    dfs(0, 100.0, 0)
    print(f'#{tc} {max_prob:.6f}')
