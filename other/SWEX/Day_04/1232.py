import sys
sys.stdin = open('input.txt', 'r')
for tc in range(1, 11):
    N = int(input())
    cur = 1
    tree = [0] * (N+1)
    stk = []
    for _ in range(N):
        inp = list(input().split())
        if len(inp) == 2:
            tree[int(inp[0])] = int(inp[1])
        else:
            stk.append((int(inp[0]), inp[1], int(inp[2]), int(inp[3])))

    # 스택 순서로 연산하면, 상위 노드에 방해받지 않고 하위 노드들 우선 처리 가능
    while stk:
        idx, op, l, r = stk.pop()
        if op == '+':
            tree[idx] = tree[l] + tree[r]
        elif op == '-':
            tree[idx] = tree[l] - tree[r]
        elif op == '*':
            tree[idx] = tree[l] * tree[r]
        elif op == '/':
            tree[idx] = tree[l] / tree[r]
    print(f"#{tc} {tree[1]:.0f}")
