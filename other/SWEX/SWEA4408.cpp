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
    int dep[201] = {0}; // 출발지의 방 번호 그룹에 있는 사람 수
    int arr[201] = {0}; // 도착 지점 그룹
    scanf("%d", &N);
    rep(i,0,N) {
        int A,B;
        scanf("%d %d", &A, &B);

        // 계산의 편의를 위해 출발지는 도착지보다 항상 빠르도록 바꿔준다.
        if (A > B) {
            int temp = A;
            A = B;
            B = temp;
        }
        dep[(A-1)/2]++;
        arr[(B-1)/2]++;
    }

    // 각 방 그룹을 순회하며 이 경로를 이용하는 사람 수의 최대값을 구한다.
    int maxStd = 0, curStd = 0;
    rep(i,0,200) {
        curStd += dep[i];
        if (curStd > maxStd) maxStd = curStd;
        curStd -= arr[i];
    }

    printf("#%d %d\n", TCnum, maxStd);
}