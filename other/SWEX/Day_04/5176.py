import sys
sys.stdin = open('input.txt', 'r')

cur = 0
def tree_travel(tree, c, N):
    global cur
    if c > N:
        return
    tree_travel(tree, c*2, N)
    tree[c] = cur
    cur += 1
    tree_travel(tree, c*2+1, N)


T = int(input())
for tc in range(1, T+1):
    N = int(input())
    cur = 1
    tree = [0] * (N+1)
    tree_travel(tree, 1, N)
    print(f"#{tc} {tree[1]} {tree[N//2]}")