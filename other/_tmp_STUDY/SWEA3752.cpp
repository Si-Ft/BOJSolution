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
    bool dp[10001] = {true,}; // dp[i] = i를 만들 수 있는지 여부
    int N;
    scanf("%d", &N);
    rep(i,0,N) {
        int num;
        scanf("%d", &num);

        for (int j=10000; j>=num; j--) {
            if (dp[j-num]) dp[j] = true;
        }
    }

    int count = 0;
    rep(i,0,10001) {
        if (dp[i]) count++;
    }

    printf("#%d %d\n", TCnum, count);
}