#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<pair<int, int>> hw;
priority_queue<
    int,
    vector<int>,
    less<int>
> nextHW;

int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) {
        int d,w;
        scanf("%d %d", &d, &w);
        hw.emplace_back(d,w);
    }
    sort(hw.begin(), hw.end());

    int ans=0;
    for (int i=hw.back().first; i>0; i--) {
        while(hw.back().first == i) {
            nextHW.push(hw.back().second);
            hw.pop_back();
        }

        if (!nextHW.empty()) {
            ans += nextHW.top();
            nextHW.pop();
        }
    }

    printf("%d", ans);
    return 0;
}