#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    int N,M;
    scanf("%d %d", &N, &M);
    int mask = (1<<N) - 1;
    // printf("%d ", mask);
    if ((M & mask) == mask) printf("#%d ON\n", TCnum);
    else printf("#%d OFF\n", TCnum);
}