#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N, v;
    int ans=0;
    scanf("%d", &N);
    int arr[101] = {0};
    rep(i,0,N) scanf("%d", arr+i);
    scanf("%d", &v);
    rep(i,0,N) if (arr[i] == v) ans++;

    printf("%d", ans);
    return 0;
}