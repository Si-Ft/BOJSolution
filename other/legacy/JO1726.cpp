#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void treeUpdate(int x, int targetAddr, int start, int end, int treeAddr);
int treeQuery(int left, int right, int start, int end, int treeAddr);

// 값은 범위 내 값들 중 최대값
int segTree[131072] = {0};

int main() {
    int N,Q;
    scanf("%d %d",&N,&Q);
    rep(i,0,N) {
        int a;
        scanf("%d",&a);
        treeUpdate(a,i+1,1,N,1);
    }
    rep(i,0,Q) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",treeQuery(a,b,1,N,1));
    }

    return 0;
}

void treeUpdate(int x, int targetAddr, int start, int end, int treeAddr) {
    segTree[treeAddr] = max(segTree[treeAddr], x);
    if (start == end) return;
    int mid = (start+end) / 2;
    if (targetAddr <= mid) treeUpdate(x,targetAddr,start,mid,treeAddr*2);
    else treeUpdate(x,targetAddr,mid+1,end,treeAddr*2+1);
}

int treeQuery(int left, int right, int start, int end, int treeAddr) {
    if (left > right) return 0;
    if (right < start || left > end) return 0;
    if (left <= start && right >= end) return segTree[treeAddr];

    // 트리분할
    int mid = (start+end) / 2;
    // 최대치만 리턴
    return max(treeQuery(left,right,start,mid,treeAddr*2) 
        ,treeQuery(left,right,mid+1,end,treeAddr*2+1));
}