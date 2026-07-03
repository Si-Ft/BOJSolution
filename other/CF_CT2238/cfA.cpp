#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bn 100000000
using namespace std;

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    int n,c;
    int A[101], B[101];
    scanf("%d %d",&n,&c);

    rep(i,0,n) scanf("%d",&A[i]);
    rep(i,0,n) scanf("%d",&B[i]);

    // 정렬 안한 경우 -> 수열 그대로 계산
    int a1 = 0;
    rep(i,0,n) {
        if (A[i] < B[i]) {
            a1 = bn;
            break;
        }
        a1 += A[i] - B[i];
    }

    // 정렬한 경우 -> 수열 정렬 후 계산
    sort(A, A+n);
    sort(B, B+n);

    int a2 = c;
    rep(i,0,n) {
        if (A[i] < B[i]) {
            a2 = bn;
            break;
        }
        a2 += A[i] - B[i];
    }

    if (a1 == bn && a2 == bn) printf("-1\n");
    else printf("%d\n", a1<a2?a1:a2);
    
}