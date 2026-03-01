#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> visited(101,0);
vector<int> dist(101,__INT_MAX__);

vector<vector<pair<int,int>>> edge(100001);
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> nextVertex;

void dijkstra(int vertex);

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    for (int i=0;i<m;i++) {
        int U,V,W;
        scanf("%d %d %d", &U, &V, &W);
        edge[U].emplace_back(V,W);
    }

    for (int i=1;i<=n;i++) {
        dist[i] = 0;
        dijkstra(i);
        for (int j=1;j<=n;j++) {
            if (dist[j] == __INT_MAX__) dist[j]=0;
            printf("%d", dist[j]);
            if (j==n) printf("\n");
            else printf(" ");
        }
        fill(visited.begin(),visited.end(),0);
        fill(dist.begin(),dist.end(),__INT_MAX__);
        while(!nextVertex.empty()) nextVertex.pop();
    }

    return 0;
}

void dijkstra(int vertex){
    // vertex 번호 에서 시작하는 모든 간선을 돌아보기
    for (pair<int,int> curEdge : edge[vertex]) {
        // ( 목적지 vertex 값 > 현재 거리 + weight ) 이면 목적지값 갱신
        if (dist[curEdge.first] > dist[vertex] + curEdge.second) {
            dist[curEdge.first] = dist[vertex] + curEdge.second;
            nextVertex.emplace(dist[curEdge.first],curEdge.first);
        }
    }
    visited[vertex] = 1;

    // 다음으로 순회할 간선을 체크
    while(!nextVertex.empty()) {
        auto vertexNum = nextVertex.top();
        nextVertex.pop();
        if (visited[vertexNum.second]) continue;
        dijkstra(vertexNum.second);
        break;
    }
}