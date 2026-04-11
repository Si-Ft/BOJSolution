#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int segTree[262145] = {0};

// 1~N 까지 전부 1로 초기화
void treeInitial(int start, int end, int treeAddr);

// 뺄 수, (전체 범위 시작, 끝, 트리주소)
void treeUpdate(int x, int start, int end, int treeAddr);

// 누적합 결과 기준 찾는 수, (전체 범위 시작, 끝, 트리주소)
int treeQuery(int findIdx, int start, int end, int treeAddr);

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    treeInitial(1, N, 1);

    int idx = 0; // 찾으려는 상대적 index
    int pool = N; // 남은 숫자 수
    printf("<");
    rep(i,0,N) {
        if (i!=0) printf(", ");
        idx = (idx-1+K)%pool;
        int v = treeQuery(idx+1, 1, N, 1);
        treeUpdate(v, 1, N, 1);
        printf("%d", v);
        pool--;
    }
    printf(">");

    return 0;
}

void treeInitial(int start, int end, int treeAddr) {
    if (start == end) {
        segTree[treeAddr] = 1;
        return;
    }
    int mid = (start+end) / 2;
    treeInitial(start, mid, treeAddr*2);
    treeInitial(mid+1, end, treeAddr*2+1);
    segTree[treeAddr] = segTree[treeAddr*2] + segTree[treeAddr*2+1];
}

void treeUpdate(int x, int start, int end, int treeAddr) {
    segTree[treeAddr] -= 1;
    if (start == end) return;
    int mid = (start+end) / 2;
    if (x <= mid) treeUpdate(x,start,mid,treeAddr*2);
    else treeUpdate(x,mid+1,end,treeAddr*2+1);
}

int treeQuery(int findIdx, int start, int end, int treeAddr) {
    if (start == end) return end;

    int mid = (start+end) / 2;
    if (segTree[treeAddr*2] >= findIdx) {
        return treeQuery(findIdx, start, mid, treeAddr*2);
    } else {
        return treeQuery(findIdx-segTree[treeAddr*2], mid+1, end, treeAddr*2+1);
    }
}