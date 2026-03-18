#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)

int nums[100001];

int main() {
    int N,S;
    scanf("%d %d", &N, &S);
    rep(i,0,N) scanf("%d", nums+i);

    int tot=0, sLength=__INT_MAX__;
    int sPtr=0, ePtr=0;
    while (1) {
        if (tot < S) {
            if (ePtr >= N) break;
            tot += nums[ePtr];
            ePtr++;
        }
        else {
            sLength = std::min(sLength, ePtr-sPtr);
            tot -= nums[sPtr];
            sPtr++;
        }
    }

    if (sLength == __INT_MAX__) printf("0");
    else printf("%d", sLength);
    
    return 0;
}