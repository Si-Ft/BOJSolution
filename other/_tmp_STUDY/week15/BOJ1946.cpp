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
    int N;
    scanf("%d", &N);
    vector<pair<int,int>> p(N);
    rep(i,0,N) scanf("%d %d", &p[i].first, &p[i].second);
    sort(p.begin(), p.end());       // 오름차순 출력
    int count = 1;
    int msec = p[0].second;         // 각 합격자마다 후순위의 점수 커트라인을 갱신 (이거 이해하기 힘들었음)
    rep(i,1,N) {
        if(p[i].second < msec) {
            count++;
            msec = p[i].second;
        }
    }
    printf("%d\n", count);
}