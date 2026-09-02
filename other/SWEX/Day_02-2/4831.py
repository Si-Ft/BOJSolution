T = int(input())
for tc in range(1,T+1):
    step, n, m = map(int, input().split())
    stops = list(map(int, input().split()))

    realans=0
    ans=0
    recent=0
    cur=step
    while recent != cur:
        if cur >= n:
            realans = ans
            break
        if cur not in stops:
            cur -= 1
            continue
        ans += 1
        recent = cur
        cur += step

    print(f"#{tc} {realans}")
