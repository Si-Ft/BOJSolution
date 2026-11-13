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
    char s[31];
    scanf("%s ", s);
    // 패턴 길이가 i라고 가정
    rep(i,1,11) {
        rep(j,i,30) {
            if(s[j] != s[j-i]) break;
            if(j == 29) {
                printf("#%d %d\n", TCnum, i);
                return;
            }
        }
    }
    printf("#%d -1\n", TCnum);
}