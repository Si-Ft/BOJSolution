#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> visited(20001,0);
vector<int> dist(20001,__INT_MAX__);

vector<vector<pair<int,int>>> edge(20001);
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> nextVertex;

void dijkstra(int vertex);

int main() {
    int v,e,start;
    scanf("%d %d %d", &v, &e, &start);
    dist[start] = 0;
    // 모든 간선 투입 (왕복으로)
    for (int i=0;i<e;i++) {
        int U,V,W;
        scanf("%d %d %d", &U, &V, &W);
        edge[U].emplace_back(V,W);
        //edge[V].emplace_back(U,W);
    }
    dijkstra(start);
    
    for (int i=1;i<=v;i++) {
        if (dist[i] == __INT_MAX__) {
            printf("INF\n");
            continue;
        }
        printf("%d\n", dist[i]);
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