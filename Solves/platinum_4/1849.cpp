#include <stdio.h>
#include <assert.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

int N;
int leafstart = 1;
int segtree[262144] = {0};
int ans[100000];

// 인덱스 leafstart ~ leafstart+k까지의 합이 target 이상이 되는 첫 번째 리프 노드를 찾는 함수
int search(int idx, int target) {
    while(idx < leafstart) {
        if(segtree[2*idx] >= target) {
            idx = 2*idx;
        } else {
            target -= segtree[2*idx];
            idx = 2*idx + 1;
        }
    }
    return idx;
}

// 해당하는 인덱스의 수를 0으로 만들고, 상위 노드들 갱신. 인덱스 값은 세그트리 기준
void update(int idx) {
    segtree[idx] = 0;
    while(idx>1) {
        idx /= 2;
        segtree[idx] -= 1;
        assert(segtree[idx] >= 0);
    }
}

int main() {
    scanf("%d", &N);

    // 세그먼트 트리 초기화. 모든 리프노드는 1부터
    // 입력을 받으면서 해당하는 위치의 값을 0으로 반환하는 방식으로 풀이
    // 리프노드의 시작은 leafstart번 인덱스부터
    while(leafstart < N) leafstart *= 2;
    rep(i,leafstart,leafstart+N) segtree[i] = 1;
    rrep(i,leafstart-1,0) segtree[i] = segtree[2*i] + segtree[2*i+1];

    rep(i,0,N) {
        int inp;
        scanf("%d", &inp);
        int idx = search(1, inp+1);
        ans[idx-leafstart] = i + 1;
        // printf("leafidx : %d\n", idx - leafstart);
        update(idx);
    }
    rep(i,0,N) printf("%d\n", ans[i]);
    
    return 0;
}