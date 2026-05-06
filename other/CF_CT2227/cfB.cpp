#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void PS(int TCnum);

int main() {
    int T;
    scanf("%d ", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    int n;
    scanf("%d ", &n);

    // int stk = 0;
    // int minStk = 0;
    // char prev = 0;
    // int combo = 0;
    // int maxCombo = 0;
    // for (int i=0; i<n; i++) {
    //     char c;
    //     scanf("%c", &c);
    //     if (c == '(') stk++;
    //     else stk--;
    //     minStk = min(minStk, stk);

    //     if (prev == c) combo++;
    //     else combo = 1;
    //     prev = c;
    //     maxCombo = max(maxCombo, combo);
    // }

    // if (minStk < -maxCombo) printf("NO\n");
    // else if (stk != 0) printf("NO\n");
    // else printf("YES\n");

    int stk=0;
    for (int i=0; i<n; i++) {
        char c;
        scanf("%c", &c);
        if (c == '(') stk++;
        else stk--;
    }

    if (stk != 0) printf("NO\n");
    else printf("YES\n");
}