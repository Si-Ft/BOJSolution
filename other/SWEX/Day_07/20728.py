import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = 10**9
    # st, en 투 포인터를 이용해 window 구현
    for en in range(K - 1, N):
        st = en - K + 1
        ans = min(ans, arr[en] - arr[st])
    print(f'#{tc} {ans}')