#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<int> arrA;
vector<int> arrB;

int main() {
    int T,n,m;
    int A[1001] = {0}, B[1001] = {0}; // 누적합을 저장함
    scanf("%d %d", &T, &n);
    rep(i,1,n+1) {
        scanf("%d", A+i);
        if (i==0) continue;
        A[i] += A[i-1];
    }
    scanf("%d", &m);
    rep(i,1,m+1) {
        scanf("%d", B+i);
        if (i==0) continue;
        B[i] += B[i-1];
    }

    rep(i,1,n+1) rep(j,i,n+1) arrA.push_back(A[j] - A[i-1]);
    rep(i,1,m+1) rep(j,i,m+1) arrB.push_back(B[j] - B[i-1]);
    sort(arrA.begin(), arrA.end());
    sort(arrB.begin(), arrB.end());

    int Aptr = 0;
    int Bptr = arrB.size()-1;
    long long tot = 0;
    while(1) {
        if (Bptr < 0 || Aptr >= arrA.size()) break;

        int ABsum = arrA[Aptr] + arrB[Bptr];
        if (ABsum < T) {
            Aptr++;
            continue;
        }
        if (ABsum > T) {
            Bptr--;
            continue;
        }

        int Acombo = 1;
        int Bcombo = 1;
        while (1) {
            if (Aptr >= arrA.size()-1) break;
            if (arrA[Aptr] != arrA[Aptr+1]) break;
            Acombo++;
            Aptr++;
        }
        while (1) {
            if (Bptr <= 0) break;
            if (arrB[Bptr] != arrB[Bptr-1]) break;
            Bcombo++;
            Bptr--;
        }

        tot += (long long)Acombo * Bcombo;
        Aptr++;
        Bptr--;
    }

    printf("%lld", tot);

    return 0;
}