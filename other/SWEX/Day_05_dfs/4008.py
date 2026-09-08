import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    op = list(map(int, input().split()))
    numb = list(map(int, input().split()))

    max_val = -100000001
    min_val = 100000001
    def dfs(depth, cur_val, cur_op):
        global max_val, min_val
        if depth == N:
            max_val = max(max_val, cur_val)
            min_val = min(min_val, cur_val)
            return
        
        for i in range(4):
            if cur_op[i] <= 0:
                continue
            next_op = cur_op[:]
            next_op[i] -= 1
            if i == 0:
                dfs(depth + 1, cur_val + numb[depth], next_op)
            elif i == 1:
                dfs(depth + 1, cur_val - numb[depth], next_op)
            elif i == 2:
                dfs(depth + 1, cur_val * numb[depth], next_op)
            elif i == 3:
                dfs(depth + 1, int(cur_val / numb[depth]), next_op)

    dfs(1, numb[0], op[:])
    print(f'#{tc} {max_val - min_val}')