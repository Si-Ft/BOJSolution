#include <vector>

using namespace std;

const int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int dp[502][502][3] = {0};      // 0 : 전체 가능한 경우의 수 | 1,2 : 가로방향, 세로방향 통행 경우의 수 (city_map이 2인 경우)
    dp[0][0][0] = 1;

    // 첫 가로줄 체크
    for (int i=1; i<n; i++) {
        if (city_map[0][i] == 1) break;
        dp[0][i][0] = dp[0][i-1][0];
        if (city_map[0][i] == 2) dp[0][i][1] = dp[0][i][0];
    }

    // 첫 세로줄 체크
    for (int i=1; i<m; i++) {
        if (city_map[i][0] == 1) break;
        dp[i][0][0] = dp[i-1][0][0];
        if (city_map[i][0] == 2) dp[i][0][2] = dp[i][0][0];
    }

    for (int y=1; y<m; y++) {
        for (int x=1; x<n; x++) {
            if (city_map[y][x] == 1) continue;

            // 왼쪽에서 오는 경우
            int left;
            if (city_map[y][x-1] == 2) left = dp[y][x-1][1];
            else left = dp[y][x-1][0];

            // 위에서 오는 경우
            int top;
            if (city_map[y-1][x] == 2) top = dp[y-1][x][2];
            else top = dp[y-1][x][0];

            dp[y][x][0] = (left + top) % MOD;
            dp[y][x][1] = left;
            dp[y][x][2] = top;
        }
    }
    answer = dp[m-1][n-1][0];

    return answer;
}