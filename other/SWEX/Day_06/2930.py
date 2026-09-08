import sys
sys.stdin = open('input.txt', 'r')

import heapq
T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    heap = []
    res = []
    for _ in range(N):
        quer = list(map(int, input().split()))
        if quer[0] == 1:
            heapq.heappush(heap, -quer[1])
        elif quer[0] == 2:
            ret = None
            if heap:
                ret = -heapq.heappop(heap)
            else:
                ret = -1
            res.append(ret)
    print(f"#{tc}", *res)