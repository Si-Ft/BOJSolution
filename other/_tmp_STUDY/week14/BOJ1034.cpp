#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

unordered_map<long long, int> mp;     // key: 열기준 비트마스크값, value: 개수
int main() {
    int N,M,K;
    scanf("%d %d", &N, &M);

    rep(i,0,N) {
        char inp[51];
        scanf("%s", inp);
        long long bitmask = 0;
        rep(j,0,M) {
            if (inp[j] == '1') bitmask |= (1LL << j);
        }
        mp[bitmask]++;
    }

    scanf("%d", &K);


    // 각 수를 보면서 비트를 1로 만들어야 하는 개수를 확인
    int ans = 0;
    for (pair<long long,int> p : mp) {
        long long num = p.first;

        int need = 0;
        rep(i,0,M) {
            if ((num & (1LL << i)) == 0) need++;
        }

        // 조건 만족 여부
        if (need > K) continue;
        if ((K - need) % 2 != 0) continue;

        ans = max(ans, p.second);
    }

    printf("%d\n", ans);

    return 0;
}