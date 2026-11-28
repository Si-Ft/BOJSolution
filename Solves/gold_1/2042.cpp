#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

int N, M, K;
long long segtree[1<<21];
int tsize;

// 바텀업 방식 단일 값 업데이트
void update(long long val, int idx) {
    idx += tsize;
    segtree[idx] = val;
    while(idx-1) {
        idx /= 2;
        segtree[idx] = segtree[idx*2] + segtree[idx*2+1];
    }
}

// 탑다운 방식 범위값 구하기
long long query(int start, int end, int l, int r, int tidx) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return segtree[tidx];
    int mid = (start+end)/2;
    return query(start, mid, l, r, tidx*2) + query(mid+1, end, l, r, tidx*2+1);
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    tsize = 1;
    while(tsize < N) tsize <<= 1;
    rep(i,0,N) scanf("%lld", &segtree[tsize+i]);
    rrep(i,tsize-1, 0) segtree[i] = segtree[i*2] + segtree[i*2+1];

    rep(i,0,M+K) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            int b;
            long long c;
            scanf("%d %lld", &b, &c);
            update(c, b-1);
        } else {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", query(0, tsize-1, b-1, c-1, 1));
        }
    }

    return 0;
}