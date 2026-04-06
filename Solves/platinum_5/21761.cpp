#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<vector<int>> cards(4); // 0-A | 3-D

int main() {
    int N,K;
    scanf("%d %d", &N, &K);
    long long len[4];
    scanf("%lld %lld %lld %lld", len, len+1, len+2, len+3);

    rep(i,0,N) {
        char c;
        int inc;
        scanf(" %c %d", &c, &inc);
        cards[c-'A'].push_back(inc);
    }
    rep(i,0,4) sort(cards[i].begin(), cards[i].end());

    rep(i,0,K) {
        int maxaddr = -1;

        // 카드가 비었을 때는 전혀 고려하지 않음
        rep(j,0,4) {
            if (cards[j].empty()) continue;
            if (maxaddr == -1) {
                maxaddr = j;
                continue;
            }
            __int128 val1 = (__int128)(len[maxaddr] + cards[maxaddr].back()) * len[j];
            __int128 val2 = (__int128)(len[j] + cards[j].back()) * len[maxaddr];

            if (val1 < val2) maxaddr = j;
        }

        printf("%c %d\n", maxaddr+'A', cards[maxaddr].back());
        len[maxaddr] += cards[maxaddr].back();
        cards[maxaddr].pop_back();
    }

    return 0;
}