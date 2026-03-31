#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

multiset<int> bagSize;
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    less<pair<int,int>>
> jewelInfo;

int main() {
    int N,K;
    long long tot = 0;
    scanf("%d %d", &N, &K);
    rep(i,0,N) {
        int M,V;
        scanf("%d %d", &M, &V);
        jewelInfo.emplace(V,M);
    }
    rep(i,0,K) {
        int C;
        scanf("%d", &C);
        bagSize.insert(C);
    }

    while (!jewelInfo.empty() && !bagSize.empty()) {
        int jV = jewelInfo.top().first;
        int jM = jewelInfo.top().second;
        jewelInfo.pop();
        auto bagAddr = bagSize.lower_bound(jM);
        if (bagAddr == bagSize.end()) continue;
        bagSize.erase(bagAddr);
        tot = tot + jV;
    }
    
    printf("%lld", tot);

    return 0;
}