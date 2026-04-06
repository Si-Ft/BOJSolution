#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int N;
int lis[1000001];
int endlisAddr = 0;

void changeLowerbound(int num);

// 동일 코드로 12738 문제도 가능
int main() {
    int N, inp;
    scanf("%d", &N);
    scanf("%d", &inp);
    lis[0] = inp;
    rep(i,1,N) {
        scanf("%d", &inp);
        if (lis[endlisAddr] < inp) {
            endlisAddr++;
            lis[endlisAddr] = inp;
        }
        else changeLowerbound(inp);
    }
    printf("%d", endlisAddr+1);

    return 0;
}

void changeLowerbound(int num){
    int start=0, end=endlisAddr;
    while(start<end) {
        int mid = (start+end)/2;
        if (lis[mid] < num) start = mid+1;
        else end = mid;
    }
    lis[end] = num;
}