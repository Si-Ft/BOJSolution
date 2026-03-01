#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int,int>>> edge(10001); // 두 마을 사이의 거리
vector<vector<pair<int,int>>> revEdge(10001); // 두 마을 사이의 거리 (역방향)
vector<int> visited(1001,0); // 다익스트라 계산_ 방문체크
vector<int> dist(1001,__INT_MAX__); // 다익스트라 계산_ 거리 체크
vector<int> revDist(1001,__INT_MAX__); // 다익스트라 계산_ 거리 체크

priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> nextVertex; // 다익스트라 시 다음에 계산할 마을

void dijkstra(int vertex, const vector<vector<pair<int,int>>>& graph, vector<int>& D);
int N,M,X;

int main() {
    scanf("%d %d %d",&N,&M,&X);
    dist[X] = 0;
    revDist[X] = 0;
    for (int i=0;i<M;i++) {
        int U,V,W;
        scanf("%d %d %d", &U, &V, &W);
        edge[U].emplace_back(V,W);
        revEdge[V].emplace_back(U,W);
    }
    dijkstra(X,edge,dist);
    while(!nextVertex.empty()) nextVertex.pop();
    fill(visited.begin(), visited.end(), 0);
    dijkstra(X,revEdge,revDist);

    int mx = 0;
    for (int i=1;i<=N;i++) {
        //printf("%d %d\n", dist[i], revDist[i]);
        mx = max(mx, dist[i] + revDist[i]);
    }
    printf("%d", mx);

    return 0;
}

void dijkstra(int vertex, const vector<vector<pair<int,int>>>& graph, vector<int>& D){
    // vertex 번호 에서 시작하는 모든 간선을 돌아보기
    for (pair<int,int> curEdge : graph[vertex]) {
        // ( 목적지 vertex 값 > 현재 거리 + weight ) 이면 목적지값 갱신
        if (D[curEdge.first] > D[vertex] + curEdge.second) {
            D[curEdge.first] = D[vertex] + curEdge.second;
            nextVertex.emplace(D[curEdge.first],curEdge.first);
        }
    }
    visited[vertex] = 1;

    // 다음으로 순회할 간선을 체크
    while(!nextVertex.empty()) {
        auto vertexNum = nextVertex.top();
        nextVertex.pop();
        if (visited[vertexNum.second]) continue;
        dijkstra(vertexNum.second, graph, D);
        break;
    }
}