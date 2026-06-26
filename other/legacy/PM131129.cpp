#include <string>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int dp[100001][2] = {0};

// DP값 갱신 (이전 target값, 현재 target값, 불이나 싱글 여부)
void calDP(int prev, int cur, bool isbs) {
    int bs = isbs ? 1 : 0;
    if (prev < 0) return;
    // 최소 횟수를 갱신 가능할 때 (불과 싱글 합 강제 갱신)
    if ((dp[prev][0] + 1) < dp[cur][0]) {
        dp[cur][0] = dp[prev][0] + 1;
        dp[cur][1] = dp[prev][1] + bs;
        return;
    }
    // 최소 횟수가 같으면, max(불과 싱글 이전합, 현재합)
    else if ((dp[prev][0] + 1) == dp[cur][0]) {
        dp[cur][1] = max(dp[cur][1], dp[prev][1] + bs);
    }

}

vector<int> solution(int target) {
    // target 점수에 대해서 최소 횟수 & 불과 싱글의 최대 횟수
    
    rep(i,1,target+1) {
        dp[i][0] = 200001;
        dp[i][1] = 0;
    }

    rep(i,1,target+1) {
        rep(j,1,21) calDP(i-(j*1), i, true);    // 1. 싱글
        rep(j,1,21) calDP(i-(j*2), i, false);   // 2. 더블
        rep(j,1,21) calDP(i-(j*3), i, false);   // 3. 트리플
        calDP(i-50, i, true);                   // 4. 불
    }

    vector<int> answer;
    answer.push_back(dp[target][0]);
    answer.push_back(dp[target][1]);
    return answer;
}