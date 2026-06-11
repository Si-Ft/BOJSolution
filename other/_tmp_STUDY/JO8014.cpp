#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<pair<int, int>> trees; // 나무의 x,y좌표
int N, T; // 필드의 너비, 나무의 개수

int findMaxSquare(int lb, int rb, int w);

int main() {
    scanf("%d %d", &N, &T);
    trees.emplace_back(0, 0); // border의 좌상단 경계를 0, 0에 있는 나무로 퉁침
    trees.emplace_back(N+1, N+1); // border의 우하단 경계를 N+1, N+1에 있는 나무로 퉁침
    rep(i,0,T) {
        int x,y;
        scanf("%d %d", &x, &y);
        trees.emplace_back(x,y);
    }
    sort(trees.begin(), trees.end());   // x좌표 오름차순으로 정렬

    int ans = 0;
    
    rep(i,0,T+2) {
        int lx = trees[i].first + 1;        // 왼쪽 x좌표 경계
        rep(j,i+1,T+2) {
            int rx = trees[j].first - 1;    // 오른쪽 x좌표 경계
            int width = rx - lx + 1;          // 가능한 너비

            if (width <= ans) continue; // 볼 필요 없는 경우
            if (width <= 0) continue;   // 두 나무의 거리가 0 이하라면 불가능

            int maxSquare = findMaxSquare(lx, rx, width);
            ans = max(ans, maxSquare);
        }
    }

    printf("%d\n", ans);
    return 0;
}

// 좌측 경계, 우측 경계, 너비를 이용해 현재 경계에서 만들 수 있는 최대 정사각형 크기
int findMaxSquare(int lb, int rb, int w) {
    vector<int> treeYs;
    treeYs.push_back(0);
    treeYs.push_back(N+1);
    rep(i,0,T+2) {
        int x = trees[i].first;     // 나무의 x좌표
        int y = trees[i].second;    // 나무의 y좌표
        if (x < lb || x > rb) continue;    // 나무가 현재 경계 밖에 있다면 무시
        treeYs.push_back(y);
    }

    sort(treeYs.begin(), treeYs.end());   // y좌표 오름차순으로 정렬
    int maxH = 0;
    rep(i,1,treeYs.size()) {
        // 가능한 최대 높이
        maxH = max(maxH, treeYs[i] - treeYs[i-1] - 1);
    }
    return min(w, maxH);
}