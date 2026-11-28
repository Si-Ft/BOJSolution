#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

int N, M, K;
long long segtree[1<<21] = {0};
long long lazy[1<<21] = {0};    // lazy가 적용되어있는 노드 자체는 업데이트된 값이 들어있음
int tsize;

// 현재 노드에서 lazy를 하위 노드로 전파.
void lazy_update(int tidx, int start, int end) {
    // lazy 전파
    lazy[tidx*2] += lazy[tidx];
    lazy[tidx*2+1] += lazy[tidx];
    // 자식 노드에 lazy 적용
    long long propa = (end-start+1)/2*lazy[tidx];
    segtree[tidx*2] += propa;
    segtree[tidx*2+1] += propa;
    // 현재 lazy는 비어있게 됨.
    lazy[tidx] = 0;
}

// 구간 업데이트 | 트리번호, 업데이트할 값, [함수 기준 구간], [업데이트할 실제 구간]
void update(int tidx, long long val, int start, int end, int l, int r) {
    // 범위 밖
    if(r < start || end < l) return;

    // 범위 내에 완전히 포함될 경우 (segtree의 현재 노드는 갱신됨)
    if(l <= start && end <= r) {
        lazy[tidx] += val;
        segtree[tidx] += (end-start+1)*val;
        return;
    }

    // 일부만 겹쳤을 때의 처리 방법
    // 1. push 후 재귀, 돌아와서 두 자식의 합으로 갱신
    if(lazy[tidx]) lazy_update(tidx, start, end);

    // 2. 재귀로 자식 노드 갱신 후 합으로 갱신
    int mid = (start+end)/2;
    update(tidx*2, val, start, mid, l, r);
    update(tidx*2+1, val, mid+1, end, l, r);
    segtree[tidx] = segtree[tidx*2] + segtree[tidx*2+1];
}

// 구간 합 쿼리
long long query(int tidx, int start, int end, int l, int r) {
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) return segtree[tidx];

    if(lazy[tidx]) lazy_update(tidx, start, end);

    int mid = (start+end)/2;
    return query(tidx*2, start, mid, l, r) + query(tidx*2+1, mid+1, end, l, r);
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    tsize = 1;
    while(tsize < N) tsize <<= 1;
    
    // 초기화만 bottom-up으로
    rep(i,0,N) scanf("%lld", &segtree[tsize+i]);
    rrep(i,tsize-1,0) segtree[i] = segtree[i*2] + segtree[i*2+1];

    rep(i,0,M+K) {
        int a;
        scanf("%d", &a);
        if (a==1) {     // b번째 수부터 c번째 수에 d를 더함
            int b, c;
            long long d;
            scanf("%d %d %lld", &b, &c, &d);
            update(1, d, 0, tsize-1, b-1, c-1);
        }
        else if (a==2) {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", query(1, 0, tsize-1, b-1, c-1));
        }
    }

    return 0;
}