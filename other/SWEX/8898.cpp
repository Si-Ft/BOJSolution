// 8898. 3차원 농부

#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    int N, M;
    scanf("%d %d", &N, &M);
    int c1, c2;
    scanf("%d %d", &c1, &c2);

    vector<int> cows(N), horses(M);
    rep(i,0,N) scanf("%d", &cows[i]);
    rep(i,0,M) scanf("%d", &horses[i]);

    sort(cows.begin(), cows.end());
    sort(horses.begin(), horses.end());

    int minGap = __INT_MAX__;
    int minCount = 0;
    int i = 0, j = 0;
    while (i < N && j < M) {
        int gap = abs(cows[i] - horses[j]);
        if (minGap > gap) {
            minGap = gap;
            minCount = 1;
        }
        else if (minGap == gap) {
            minCount++;
        }

        if (cows[i] > horses[j]) j++;
        else i++;
    }

    printf("#%d %d %d\n", TCnum, minGap + abs(c1 - c2), minCount);
}