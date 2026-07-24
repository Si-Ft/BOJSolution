#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

pair<int,int> dfs(int start);
vector<vector<pair<int,int>>> edges(100001);
int V;

int main() {
    scanf("%d", &V);
    rep(i,1,V+1) {
        int sEdge;
        scanf("%d", &sEdge);
        while(1) {
            int p,w;
            scanf("%d", &p);
            if (p == -1) break;
            scanf("%d", &w);
            edges[sEdge].emplace_back(p,w);
        }
    }

    int farNode = dfs(1).first;
    int ans = dfs(farNode).second;
    printf("%d", ans);

    return 0;
}

// 가장 먼 노드 번호, 거리
pair<int,int> dfs(int start) {
    stack<pair<int,int>> s;
    s.push({start,0});
    vector<bool> visited(V+1,false);
    visited[start] = true;
    int maxDist = 0;
    int farthestNode = start;
    while(!s.empty()) {
        auto curNode = s.top();
        int node = curNode.first;
        int dist = curNode.second;
        s.pop();
        
        if (dist > maxDist) {
            maxDist = dist;
            farthestNode = node;
        }

        for (auto edge : edges[node]) {
            int nextNode = edge.first;
            int nextWeight = edge.second;
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                s.push({nextNode, dist + nextWeight});
            }
        }
    }
    return {farthestNode, maxDist};
}