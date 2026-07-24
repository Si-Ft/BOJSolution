#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = INT_MAX;

    // B도둑을 기준으로 각 B도둑이 남긴 흔적 당 a도둑 흔적의 최소값
    vector<int> dp(m+3, INT_MAX);
    dp[0] = 0;

    for (auto lo : info) {
      int acost = lo[0];
      int bcost = lo[1];

      rrep(i, m - 1, 0) {
        // 아직 가능한 경우가 없는 경우
        if (dp[i] == INT_MAX) continue;

        // b가 훔칠 수 있으면 b가 훔침
        dp[i+bcost] = min(dp[i], dp[i+bcost]);

        // 아니면 현재 물건을 a가 훔침
        dp[i] += acost;
      }
    }

    rep(i,0,m) {
      answer = min(answer, dp[i]);
    }

    return answer>=n?-1:answer;
}