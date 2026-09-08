import sys
sys.stdin = open('input.txt', 'r')

def dfs(depth):
    global ans
    if depth == S:
        ans = max(ans, int("".join(num)))
        return

    # 모든 교환 경우의 수 탐색함
    for i in range(nlen):
        for j in range(i + 1, nlen):
            num[i], num[j] = num[j], num[i]
            dfs(depth + 1)
            num[i], num[j] = num[j], num[i]

T = int(input())
for tc in range(1, T + 1):
    num_str, S_str = input().split()
    num = list(num_str)
    S = int(S_str)
    nlen = len(num)

    # 중복 숫자 존재 -> 동일한 숫자를 교환함으로 남는 교환 횟수 태울 수 있음
    # 중복 숫자 미존재 -> 최적해 찾고, 남는 교환 횟수는 2씩 줄여서 처리. (홀수이면, 강제로 1회 교환 필요)
    has_duplicate = len(set(num)) < nlen
    decS = 1 if has_duplicate else 2

    while S > nlen:
        S -= decS

    ans = 0
    dfs(0)
    print(f"#{tc} {ans}")