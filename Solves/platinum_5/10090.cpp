#include <stdio.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)

int segTree[2097153] = {0};
void treeUpdate(int x, int start, int end, int treeAddr);
int treeQuery(int left, int right, int start, int end, int treeAddr);

int main() {
    int N;
    scanf("%d", &N);
    long long ans = 0;
    rep(i,0,N) {
        int a;
        scanf("%d", &a);
        ans = ans + treeQuery(a+1, N, 1, N, 1); // a+1 ~ N 까지 합
        treeUpdate(a, 1, N, 1); // 트리에 a 누적합 더하기
    }
    printf("%lld", ans);
    return 0;
}

// 넣는 수, (전체 범위 시작, 끝, 트리주소)
void treeUpdate(int x, int start, int end, int treeAddr) {
    segTree[treeAddr] += 1;
    if (start == end) return;
    int mid = (start+end) / 2;
    if (x <= mid) treeUpdate(x,start,mid,treeAddr*2);
    else treeUpdate(x,mid+1,end,treeAddr*2+1);
}

// 찾는 범위 left, right, (전체 범위 시작, 끝, 트리주소)
int treeQuery(int left, int right, int start, int end, int treeAddr) {
    if (left > right) return 0;
    if (right < start || left > end) return 0; // 범위 초과
    if (left <= start && right >= end) return segTree[treeAddr]; // 범위 완전히 커버
    // 트리분할
    int mid = (start+end) / 2;
    return treeQuery(left,right,start,mid,treeAddr*2) 
        + treeQuery(left,right,mid+1,end,treeAddr*2+1);
}