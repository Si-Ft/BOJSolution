import sys
sys.stdin = open('input.txt', 'r')
for i in range(1, 11):
    tmp = int(input())
    arr = list(map(int, input().split('+')))
    print(f'#{i} {sum(arr)}')