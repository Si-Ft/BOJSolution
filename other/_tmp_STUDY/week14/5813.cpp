#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=b-1;i>=a;i--)
#include <deque>
#include <utility>

using namespace std;

// const int TS = 1048576; // 트리 가지의 개수
// int tree[TS*2] = {0};


// 쿼리의 시작&끝 좌표, 현재 탐색중인 범위의 시작&끝, 현재 트리 idx
// int treeQuery(int qs, int qe, int cs, int ce, int tidx) {
//     if (qs <= cs && ce <= qe) return tree[tidx];    // 범위 완전히 겹칠 시
//     if (ce < qs || qe < cs) return 1<<30;           // 범위 아예 겹치지 않을 시

//     // 범위 일부만 겹칠 시
//     int mid = (cs+ce)/2;
//     return min(treeQuery(qs, qe, cs, mid, tidx*2), treeQuery(qs, qe, mid+1, ce, tidx*2+1));
// }

int main() {
    int N, M; // N : 노드 개수 / M : window 사이즈
    deque<pair<int,int>> dq; // pair<값, 인덱스>
    scanf("%d %d",&N, &M);

    rep(i,0,N) {
        int tmp;
        scanf("%d",&tmp);

        // back에서부터 새 값보다 큰 수는 전부 제거
        while(!dq.empty()) {
            if (dq.back().first > tmp) dq.pop_back();
            else break;
        }
        dq.push_back({tmp, i});

        // front의 수가 window 범위 벗어났으면 제거
        if (dq.front().second <= i-M) dq.pop_front();

        printf("%d ", dq.front().first);
    }


    // rep(i,0,N) scanf("%d",&tree[TS+i]);
    // rep(i,N,TS) tree[TS+i] = 1<<30;
    // rrep(i,1,TS) tree[i] = min(tree[i*2], tree[i*2+1]);

    // rep(i,0,M) {
    //     int qs = i-N+1, qe = i;
    //     if (qs < 0) qs = 0;
    //     printf("%d ", treeQuery(qs, qe, 0, TS-1, 1));
    // }

    return 0;
}