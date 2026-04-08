#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<pair<int,int>> dots;
vector<pair<int,int>> ansDots;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long res = 1LL*(x2-x1)*(y3-y1)-1LL*(y2-y1)*(x3-x1);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}

bool compare(pair<int,int> a, pair<int,int> b){
    int sx = ansDots[0].first;
    int sy = ansDots[0].second;
    int c = ccw(sx, sy, a.first, a.second, b.first, b.second);
    if (c != 0) return c > 0;
    long long distA = 1LL*(a.first-sx)*(a.first-sx) + 1LL*(a.second-sy)*(a.second-sy);
    long long distB = 1LL*(b.first-sx)*(b.first-sx) + 1LL*(b.second-sy)*(b.second-sy);
    return distA < distB;
}

int main() {
    int N;
    scanf("%d", &N);
    int startAddr=0;
    rep(i,0,N){
        int x,y;
        scanf("%d %d", &x, &y);
        dots.push_back({x,y});
        if (i==0) continue;
        if (dots[startAddr].second > y) startAddr = i;
        else if (dots[startAddr].second == y && dots[startAddr].first > x) startAddr = i;
    }

    // startAddr를 기준으로 반시계 방향 정렬
    ansDots.push_back(dots[startAddr]);
    sort(dots.begin(), dots.end(), compare);
    ansDots.pop_back();
    for (auto dot : dots) {
        ansDots.push_back(dot);
        int size = ansDots.size();

        // 3개 점이 반시계가 될 때까지
        if (size < 3) continue;
        while (size >= 3) {
            int c = ccw(ansDots[size-3].first, ansDots[size-3].second, 
                ansDots[size-2].first, ansDots[size-2].second, 
                ansDots[size-1].first, ansDots[size-1].second);
            if (c > 0) break;
            else {
                ansDots.pop_back();
                ansDots.pop_back();
                ansDots.push_back(dot);
                size--;
            }
        }
    }

    printf("%d", ansDots.size());

    return 0;
}