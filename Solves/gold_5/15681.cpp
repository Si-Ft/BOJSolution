#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int dfs(int start);
vector<vector<int>> edges(100001);
vector<int> subtree(100001,1);
vector<int> connectedEdge(100001,0);
int N,R,Q;

int main() {
    scanf("%d %d %d", &N, &R, &Q);
    connectedEdge[R] = 10;
    rep(i,0,N-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
        connectedEdge[u]++;
        connectedEdge[v]++;
    }

    queue<int> nextCheck;
    rep(i,1,N+1) if (connectedEdge[i] == 1) nextCheck.push(i);

    while (!nextCheck.empty()) {
        int node = nextCheck.front();
        nextCheck.pop();
        connectedEdge[node] = 0;
        for (int nextNode : edges[node]) {
            if (connectedEdge[nextNode] == 0) continue;
            subtree[nextNode] += subtree[node];
            connectedEdge[nextNode]--;
            if (connectedEdge[nextNode] == 1) nextCheck.push(nextNode);
        }
    }
    
    rep(i,0,Q) {
        int q;
        scanf("%d", &q);
        printf("%d\n", subtree[q]);
    }
    return 0;
}
