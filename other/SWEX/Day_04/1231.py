import sys
sys.stdin = open('input.txt', 'r')

tree = [0]
def tree_travel(c, N):
    if c > N:
        return
    tree_travel(c*2, N)
    print(tree[c], end='')
    tree_travel(c*2+1, N)

for tc in range(1, 11):
    N = int(input())
    cur = 1
    tree = [0] * (N+1)
    for _ in range(N):
        inp = list(input().split())
        tree[int(inp[0])] = inp[1]
    print(f"#{tc} ", end='')
    tree_travel(1, N)
    print()