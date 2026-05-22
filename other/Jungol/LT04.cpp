#include <stdio.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

vector<pair<int, int>> jewels; // 보석의 무게, 가치
int dp[10001] = {0}; // 무게 i로 만들 수 있는 최대 가치

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    rep(i,0,N) {
        int w, c, k;
        scanf("%d %d %d", &w, &c, &k);

        // 0/1 배낭 문제로 변환하기 위해 보석을 나누어 저장
        int count = 1;
        while (k > 0) {
            // 사용할 수 있는 보석의 개수는 k와 count 중 작은 값
            int useCount = (k < count) ? k : count; 
            jewels.emplace_back(w * useCount, c * useCount); 
            k -= useCount;
            count *= 2;
        }
    }

    rep(i,0,jewels.size()) {
        // 0-1 배낭이므로 역순으로 탐색해야 중복으로 넣지 않음.
        rrep(w, M, jewels[i].first) {
            if (dp[w] < dp[w - jewels[i].first] + jewels[i].second) {
                dp[w] = dp[w - jewels[i].first] + jewels[i].second;
            }
        }
    }

    printf("%d", dp[M]);
    return 0;
}