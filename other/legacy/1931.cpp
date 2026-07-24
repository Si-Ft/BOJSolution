#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    int N;
    vector<pair<int,int>> v;
    scanf("%d", &N);
    rep(i,0,N) {
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back({a, b});
    }

    // v를 끝나는 시간 오름차순으로 정렬
    // 동일하다면 시작 시간 오름차순으로 정렬 (회의시간 0 대비)
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    // 회의가 끝나는 시간 순서대로 회의 선택, 출발 시간이 겹치지 않도록 선택
    int count = 0;
    int last_end_time = 0;
    for (auto meeting : v) {
        if (meeting.first >= last_end_time) {
            count++;
            last_end_time = meeting.second;
        }
    }
    printf("%d\n", count);

    return 0;
}