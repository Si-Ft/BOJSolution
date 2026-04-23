#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N;
int ans = 0;
int num[2000];

bool isGoodNum(int n, int idx);

int main() {
    scanf("%d", &N);
    rep(i,0,N) scanf("%d", num+i);

    sort(num, num+N);
    rep(i,0,N) {
        if (isGoodNum(num[i], i)) ans++;
    }

    printf("%d", ans);
    return 0;
}

// idx번째에 있는 수는 빼고 계산
bool isGoodNum(int n, int idx) {
    int st = 0;
    int en = N-1;
    while(st != en) {
        if (idx == st) {
            st++; 
            continue;
        }
        if (idx == en) {
            en--;
            continue;
        }
        int curNum = num[st] + num[en];
        if (curNum < n) st++;
        else if (curNum > n) en--;
        else return true;
    }
    return false;
}