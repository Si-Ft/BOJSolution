#include <stdio.h>

void changeAll(bool *s, int cng) { for (int i=1;i<21;i++) s[i]=cng; }

int main() {
    bool S[21] = {0};
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        char C[8];
        int x;
        scanf("%s %d",C,&x);
        if (C[1]=='d') S[x]=1;
        if (C[1]=='e') S[x]=0;
        if (C[1]=='h') printf("%d\n",S[x]);
        if (C[1]=='o') S[x]=!S[x];
        if (C[1]=='l') changeAll(S,1);
        if (C[1]=='m') changeAll(S,0);
    }
    return 0;
}