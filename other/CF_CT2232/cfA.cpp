#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    int N;
    int A[101];
    scanf("%d", &N);
    rep(i,0,N) scanf("%d", A+i);

    sort(A, A+N);

    int lp=0, rp=1;
    int ans = __INT_MAX__;
    while (rp < N) {
        while(rp < N && A[lp] == A[rp]) rp++;
        int leftPerson = lp;
        int rightPerson = N-rp;
        int comeBoth = min(leftPerson, rightPerson);
        leftPerson -= comeBoth;
        rightPerson -= comeBoth;
        ans = min(ans, comeBoth + leftPerson + rightPerson);
        lp = rp;
    }
    printf("%d\n", ans);
}