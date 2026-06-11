#include <string>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());

    // 이분 탐색을 이용해 최소 거리의 최대값을 찾음
    int left = 0, right = distance;
    int curDist = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int removed = 0;    // 제거한 돌의 개수
        curDist = 0;        // 구간 시작 지점

        bool canRemove = true; // mid 거리로 돌을 제거할 수 있는지 여부
        for (int rock : rocks) {
            // 구간의 거리가 조건을 만족하지 못하면, 돌을 제거
            if (rock - curDist < mid) {
                removed++;
                if (removed > n) {
                    canRemove = false;
                    break;
                }
            } else {
                // 구간 시작 지점 갱신
                curDist = rock;
            }
        }
        // 마지막 돌 <-> 도착 지점 거리 확인
        if (distance - curDist < mid) {
            removed++;
            if (removed > n) canRemove = false;
        }
        if (canRemove) {
            answer = mid;   // 가능한 거리 갱신
            left = mid + 1; // 더 큰 거리 시도
        } else right = mid - 1; // 더 작은 거리 시도
    }

    return answer;
}