import sys
sys.stdin = open('input.txt', 'r')

from collections import deque
for _ in range(1, 11):
    tc = int(input())
    arr = list(map(int, input().split()))

    allmin = (min(arr)-15) // 15 * 15
    arr = [x - allmin for x in arr]

    queue = deque(arr)
    decnum = 1
    while True:
        num = queue.popleft()
        num -= decnum
        if num <= 0:
            queue.append(0)
            break
        queue.append(num)
        decnum = decnum + 1 if decnum < 5 else 1

    print(f'#{tc} {" ".join(map(str, queue))}')

    