#include <stdio.h>
#include <numeric>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    int n = TCnum;
    scanf("%d",&n);
    long long ans = 0;
    rep(i,1,n+1) {
        ans += (long long)(n/i)*(n/i);
    }
    printf("%lld\n", ans);
}