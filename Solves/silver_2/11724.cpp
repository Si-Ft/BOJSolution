#include <stdio.h>
#include <queue>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,M;
vector<vector<int>> edges(1001);
bool visited[1001] = {false};

void bfs(int start);

// 연결 요소 개수 구하기
int main() {
    scanf("%d %d", &N, &M);
    rep(i,0,M) {
        int u,v;
        scanf("%d %d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ans = 0;
    rep(i,1,N+1) {
        if (visited[i]) continue;
        bfs(i);
        ans++;
    }
    printf("%d", ans);
    return 0;
}

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int curNode = q.front();
        q.pop();
        for (int i : edges[curNode]) {
            if (visited[i]) continue;
            q.push(i);
            visited[i] = true;
        }
    }
}