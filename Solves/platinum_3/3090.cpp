#include <stdio.h>
#include <string.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int st=1<<30, en=0;
int N,T;
int A[100001];
int cpyA[100001];

bool fetchArray(int estiGap, bool prt);

int main() {
    scanf("%d %d", &N, &T);
    rep(i,0,N) {
        scanf("%d", A+i);
        if (A[i] < st) st = A[i];
        if (A[i] > en) en = A[i];
    }
    en -= st;
    st = 0;

    while (st < en) {
        int mid = (st+en)/2;
        if (fetchArray(mid, false)) en = mid;
        else st = mid+1;
    }
    fetchArray(st,true);
    return 0;
}

bool fetchArray(int estiGap, bool prt) {
    memcpy(cpyA, A, sizeof(A));
    int leftT = T;
    rep(i,1,N) {
        int reqT = cpyA[i] - (cpyA[i-1] + estiGap);
        if (reqT <= 0) continue;
        cpyA[i] -= reqT;
        leftT -= reqT;
        if (leftT < 0) return false;
    }
    rrep(i,N-2,0) {
        int reqT = cpyA[i] - (cpyA[i+1] + estiGap);
        if (reqT <= 0) continue;
        cpyA[i] -= reqT;
        leftT -= reqT;
        if (leftT < 0) return false;
    }
    if (prt) rep(i,0,N) printf("%d ", cpyA[i]);
    return true;
}