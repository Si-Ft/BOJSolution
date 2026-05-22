// 26793. 게으름뱅이 D4

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
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
    int N;
    scanf("%d", &N);

    // <데드라인, 걸리는 시간>
    vector<pair<int,int>> v(N);
    rep(i,0,N) {
        // 걸리는 시간, 데드라인 순으로 입력
        scanf("%d %d", &v[i].second, &v[i].first);
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int time = __INT_MAX__;

    for (auto c : v) {
        time = min(time, c.first) - c.second;
    }
    printf("%d\n", time);
}