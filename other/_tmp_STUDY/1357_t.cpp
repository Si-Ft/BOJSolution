#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int A[4000], B[4000], C[4000], D[4000];
int AB[16000000];
int CD[16000000];

int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) scanf("%d %d %d %d", A+i, B+i, C+i, D+i);

    // A랑 B를 합친 리스트들 || C랑 D를 합친 리스트들 쫙 뽑아서 재정렬 후, 탐색
    rep(i,0,N) {
        rep(j,0,N) {
            AB[i*N+j]=A[i]+B[j];
            CD[i*N+j]=C[i]+D[j];
        }
    }

    sort(AB,AB+(N*N));
    sort(CD,CD+(N*N));

    // 정렬 후, AB의 맨 처음(가장 작음)과 CD의 맨 마지막 부분(가장 큼)을 포인터로 잡음
    // 합이 0보다 클 시, CD포인터 감소, 0보다 작을 시, AB포인터 증가
    // 합이 0일 시, 각 배열에 동일한 수가 있을 경우 (AB수)3*(CD수)4 처럼 곱셈 처리
    int ABptr = 0;
    int CDptr = N*N-1;
    long long tot = 0;
    while(1) {
        if (CDptr < 0 || ABptr >= N*N) break;

        int ABCDsum = AB[ABptr] + CD[CDptr];
        if (ABCDsum < 0) {
            ABptr++;
            continue;
        }
        if (ABCDsum > 0) {
            CDptr--;
            continue;
        }

        // 합이 0임을 찾을 경우, 동일한 숫자가 얼마나 있는지 체크, 범위초과 주의
        int ABcombo = 1;
        int CDcombo = 1;
        while (1) {
            if (ABptr >= N*N-1) break;
            if (AB[ABptr] != AB[ABptr+1]) break;
            ABcombo++;
            ABptr++;
        }
        while (1) {
            if (CDptr <= 0) break;
            if (CD[CDptr] != CD[CDptr-1]) break;
            CDcombo++;
            CDptr--;
        }

        tot += (long long)ABcombo * CDcombo;
        ABptr++;
        CDptr--;
    }

    printf("%lld", tot);

    return 0;
}