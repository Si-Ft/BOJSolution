#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void segMaxUpdate(int x, int targetAddr, int start, int end, int treeAddr);
void segMinUpdate(int x, int targetAddr, int start, int end, int treeAddr);
int segMaxQuery(int left, int right, int start, int end, int treeAddr);
int segMinQuery(int left, int right, int start, int end, int treeAddr);

// 값은 범위 내 값들 중 최대값과 최소값
int segMax[262144] = {0};
int segMin[262144] = {0};

int main() {
    int N,Q;
    scanf("%d %d",&N,&Q);
    for (int i=0;i<262144;i++) segMin[i] = __INT_MAX__;

    rep(i,0,N) {
        int a;
        scanf("%d",&a);
        segMaxUpdate(a,i+1,1,N,1);
        segMinUpdate(a,i+1,1,N,1);
    }
    rep(i,0,Q) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d %d\n",segMinQuery(a,b,1,N,1), segMaxQuery(a,b,1,N,1));
    }

    return 0;
}

void segMaxUpdate(int x, int targetAddr, int start, int end, int treeAddr) {
    segMax[treeAddr] = max(segMax[treeAddr], x);
    if (start == end) return;
    int mid = (start+end) / 2;
    if (targetAddr <= mid) segMaxUpdate(x,targetAddr,start,mid,treeAddr*2);
    else segMaxUpdate(x,targetAddr,mid+1,end,treeAddr*2+1);
}

void segMinUpdate(int x, int targetAddr, int start, int end, int treeAddr) {
    segMin[treeAddr] = min(segMin[treeAddr], x);
    if (start == end) return;
    int mid = (start+end) / 2;
    if (targetAddr <= mid) segMinUpdate(x,targetAddr,start,mid,treeAddr*2);
    else segMinUpdate(x,targetAddr,mid+1,end,treeAddr*2+1);
}

int segMaxQuery(int left, int right, int start, int end, int treeAddr) {
    if (left > right) return 0;
    if (right < start || left > end) return 0;
    if (left <= start && right >= end) return segMax[treeAddr];

    // 트리분할
    int mid = (start+end) / 2;
    // 최대치만 리턴
    return max(segMaxQuery(left,right,start,mid,treeAddr*2) 
        ,segMaxQuery(left,right,mid+1,end,treeAddr*2+1));
}

int segMinQuery(int left, int right, int start, int end, int treeAddr) {
    if (left > right) return __INT_MAX__;
    if (right < start || left > end) return __INT_MAX__;
    if (left <= start && right >= end) return segMin[treeAddr];

    // 트리분할
    int mid = (start+end) / 2;
    // 최소치만 리턴
    return min(segMinQuery(left,right,start,mid,treeAddr*2) 
        ,segMinQuery(left,right,mid+1,end,treeAddr*2+1));
}