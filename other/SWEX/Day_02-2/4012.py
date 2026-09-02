import sys
sys.stdin = open('input.txt', 'r')

# 조합한 A음식을 기반으로 B음식 분류 후 시너지 차이 계산
def cal_score():
    global min_syn

    # A음식에 속하지 않은 음식을 B음식으로 분류
    b_food = []
    a_set = set(a_food)
    for i in range(N):
        if i not in a_set:
            b_food.append(i)

    # 시너지 계산
    a_syn = 0
    b_syn = 0
    for i in range(N // 2):
        for j in range(N // 2):
            a_syn += syn[a_food[i]][a_food[j]]
            b_syn += syn[b_food[i]][b_food[j]]

    # 최소 시너지 차이값 갱신
    min_syn = min(min_syn, abs(a_syn - b_syn))

# 조합을 이용해 A음식을 선택해둠
def combi(depth, start):
    if depth == N // 2:
        cal_score()
        return

    for i in range(start, N):
        a_food[depth] = i
        combi(depth + 1, i + 1)


T = int(input())
for tc in range(1, T+1):
    N = int(input())
    syn = [list(map(int, input().split())) for _ in range(N)]

    a_food = [0] * (N // 2)
    min_syn = float('inf')

    combi(0, 0)

    print(f'#{tc} {min_syn}')