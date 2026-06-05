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
    scanf("%d", &N);

    long long culsum = 0;
    int prevAns = -1;
    // i : 현재까지 본 숫자의 개수
    rep(i,1,N+1) {
        int num;
        scanf("%d", &num);
        culsum += num;
        if (prevAns == -1) {
            printf("%d ", num);
            prevAns = num;
            continue;
        }

        int ans = min(prevAns, (int)(culsum/i) );
        printf("%d ", ans);
        prevAns = ans;
    }
    printf("\n");
}