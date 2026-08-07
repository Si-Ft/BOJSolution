#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int ep = 99999;

    // 값 정렬 (혹시 모르니 출발 지점이 더 작은 값이도록 변경)
    for (int i=0; i<routes.size(); i++) {
        if (routes[i][0] > routes[i][1]) {
            swap(routes[i][0], routes[i][1]);
        }
    }
    sort(routes.begin(), routes.end());

    for (int i=0; i<routes.size(); i++) {
        if (routes[i][0] > ep) {
            answer++;
            ep = routes[i][1];
        }
        ep = min(ep, routes[i][1]);
    }

    return answer + 1;
}