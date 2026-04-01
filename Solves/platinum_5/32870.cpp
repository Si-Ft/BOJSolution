#include <stdio.h>
#include <algorithm>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,Q;
int A[300001];
int lbAddr[300002]; // x의 lower_bound가 있는 "주소"
int memo[300001][2] = {0}; // 최소값만 1 더해서 저장하는 식으로 쓰자..

void maxminQuery(int m, int ans[2]);

int main() {
    scanf("%d %d", &N, &Q);
    rep(i,0,N) scanf("%d", A+i);
    A[N] = 300001; // 마지막에 오버플로우 감지를 위한 값 넣기
    sort(A,A+N);

    int addr = 0; // lbAddr에 넣을 주소
    // i는 원본배열의 주소
    rep(i,0,N+1) {
        while(addr <= A[i]) {
            lbAddr[addr] = i;
            addr++;
        }
    }
    // rep(i,0,100) printf("%d ", lbAddr[i]);

    memo[1][0] = 1;
    rep(i,0,Q) {
        int quer;
        scanf("%d", &quer);
        if (memo[quer][0] != 0) {
            printf("%d %d\n", memo[quer][0]-1, memo[quer][1]);
            continue;
        }
        // 
        int ans[2];
        maxminQuery(quer, ans);
        printf("%d %d\n", ans[0], ans[1]);
        memo[quer][0] = ans[0]+1;
        memo[quer][1] = ans[1];
    }

    return 0;
}

void maxminQuery(int m, int ans[2]) {
    int sNum = 0;
    int eNum = 0;

    int minA = 300001;
    int maxA = -1;
    while(1) {
        sNum = eNum;
        eNum += m;
        minA = min(minA, A[lbAddr[sNum]] % m);
        if ((eNum > 300000) || lbAddr[eNum] == N) {
            maxA = max(maxA, A[N-1] % m);
            break;
        }
        if (lbAddr[sNum] == lbAddr[eNum]) continue;
        maxA = max(maxA, A[lbAddr[eNum]-1] % m);
    }

    ans[0] = minA;
    ans[1] = maxA;
}