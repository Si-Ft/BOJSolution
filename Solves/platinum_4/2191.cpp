#include <stdio.h>
#include <math.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<int> edges[100];
int match[100]; // index : 동굴 번호, val : 쥐 번호
bool visited[100]; // 방문한 동굴
long long mouses[100][2];
long long caves[100][2];

bool dfs(int mouse);

int main() {
    int N,M,S,V; // 들쥐 수, 땅굴 수, 제한 시간, 초당 속도
    scanf("%d %d %d %d", &N, &M, &S, &V);
    double x,y;

    // 나는 실수형이 너무 싫어
    rep(i,0,N) {
        scanf("%lf %lf", &x,&y);
        mouses[i][0] = llround(x*1000);
        mouses[i][1] = llround(y*1000);
    }
    rep(i,0,M) {
        scanf("%lf %lf", &x,&y);
        caves[i][0] = llround(x*1000);
        caves[i][1] = llround(y*1000);
    }

    // 이분 그래프 만들기
    long long moveDist = 1LL*V*V*S*S*1000000; // 움직일 수 있는 최대 거리
    rep(i,0,N) {
        rep(j,0,M) {
            // 쥐 위치와 각 땅굴 위치 거리 전부 비교, V*S보다 크면 불가능
            long long xDist = mouses[i][0] - caves[j][0];
            long long yDist = mouses[i][1] - caves[j][1];
            long long caveDist = xDist * xDist + yDist * yDist;
            if (moveDist < caveDist) continue;
            edges[i].push_back(j);
        }
    }

    rep(i,0,M) match[i] = -1;
    int ans = 0;
    rep(i,0,N) {
        rep(j,0,M) visited[j] = false;
        // dfs과정에서 모든 쥐가 새로운 자리로 움직임
        if (dfs(i)) ans++;
    }
    printf("%d", N - ans);

    return 0;
}

bool dfs(int mouse) {
    for (int cave : edges[mouse]) {
        // 쥐 빙빙 도는거 방지
        if (visited[cave]) continue;
        visited[cave] = true;

        // 동굴이 비었거나, 대상 쥐를 보낼 수 있으면
        if (match[cave] == -1 || dfs(match[cave])) {
            match[cave] = mouse;
            return true;
        }
    }
    return false;
}