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
    int N;
    scanf("%d", &N);
    const int end = (1<<10)-1;
    int visited = 0;

    int cur = 0;
    while(visited != end) {
        cur += N;
        int tmp = cur;
        while(tmp) {
            visited |= 1<<(tmp%10);
            tmp /= 10;
        }
    }
    printf("#%d %d\n", TCnum, cur);
}