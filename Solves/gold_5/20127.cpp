#include <stdio.h>
#include <queue>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    queue<int> incRange, decRange;
    int N, inp[2];
    int fN;
    scanf("%d", &N);
    rep(i,0,N) {
        scanf("%d", &inp[i%2]);
        if (i==0) {fN = inp[i%2]; continue;}
        if (inp[(i+1)%2] < inp[i%2] && (decRange.size() < 2)) decRange.push(i-1);
        if (inp[(i+1)%2] > inp[i%2] && (incRange.size() < 2)) incRange.push(i-1);
    }
    
    int k=1<<30;
    if (decRange.empty()) {printf("0"); return 0;}
    else if (decRange.size() == 1)
        if (fN <= inp[(N+1)%2]) k = min(k,decRange.front());

    if (incRange.empty()) {printf("0"); return 0;}
    else if (incRange.size() == 1)
        if (fN >= inp[(N+1)%2]) k = min(k,incRange.front());
    
    if (k>(1<<29)) printf("-1");
    else printf("%d", k+1);
    
    return 0;
}