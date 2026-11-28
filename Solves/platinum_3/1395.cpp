#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int N, M;
int segtree[1<<18] = {0};
bool lazy[1<<18] = {false};
int tsize;

void lazy_update(int idx, int start, int end) {
    // 스위칭이 필요할 때만 발동
    if(lazy[idx]) {
        int nsize = (end-start+1)/2;
        // 하위 노드를 모두 반전시켰을 때
        segtree[idx*2] = nsize - segtree[idx*2];
        segtree[idx*2+1] = nsize - segtree[idx*2+1];
        lazy[idx*2] = !lazy[idx*2];
        lazy[idx*2+1] = !lazy[idx*2+1];
        lazy[idx] = false;
    }
}

void update(int idx, int start, int end, int l, int r) {
    if (start > r || end < l) return;
    if (start >= l && end <= r) {
        int nsize = end-start+1;
        segtree[idx] = nsize - segtree[idx];
        lazy[idx] = !lazy[idx];
        return;
    }

    lazy_update(idx, start, end);
    int mid = (start+end)/2;
    update(idx*2, start, mid, l, r);
    update(idx*2+1, mid+1, end, l, r);
    segtree[idx] = segtree[idx*2] + segtree[idx*2+1]; // 역전파
}

int query(int idx, int start, int end, int l, int r) {
    if (start > r || end < l) return 0;
    if (start >= l && end <= r) return segtree[idx];

    lazy_update(idx, start, end);
    int mid = (start+end)/2;
    return query(idx*2, start, mid, l, r) + query(idx*2+1, mid+1, end, l, r);
}

int main() {
    scanf("%d %d", &N, &M);
    tsize = 1;
    while(tsize < N) tsize <<= 1;
    
    rep(i,0,M) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        if (a==0) update(1, 0, tsize-1, b-1, c-1);
        else printf("%d\n", query(1, 0, tsize-1, b-1, c-1));
    }

    return 0;
}