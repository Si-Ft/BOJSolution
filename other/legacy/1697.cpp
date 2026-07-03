#include <stdio.h>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int dist[100001] = {0};
int N,K;
int bfs(int start);

int main() {
    scanf("%d %d", &N, &K);

    dist[N] = 1;
    printf("%d", bfs(N));

    return 0;
}

int bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curnode = q.front();
        q.pop();
        if (curnode == K) { 
            // 도착지점 도달 시
            return dist[curnode]-1;
        }

        // 대상 지점을 아직 방문 안했을 때 && 갈 수 있는 지점일 때
        if (curnode-1 >= 0 && dist[curnode-1] == 0) {
            dist[curnode-1] = dist[curnode]+1;
            q.push(curnode-1);
        }
        if (curnode+1 <= 100000 && dist[curnode+1] == 0) {
            dist[curnode+1] = dist[curnode]+1;
            q.push(curnode+1);
        }
        if (curnode*2 <= 100000 && dist[curnode*2] == 0) {
            dist[curnode*2] = dist[curnode]+1;
            q.push(curnode*2);
        }
    }

    return 0;
}