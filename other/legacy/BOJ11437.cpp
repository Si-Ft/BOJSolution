#include <stdio.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<int> graph[50001];
int nodes[50001][2] = {0};    // [0] - 직계부모노드, [1] - depth수
void dfs(int parent, int depth);
int parentquery(int a, int b);

int main() {
    // 그래프 정보 삽입
    int N;
    scanf("%d", &N);
    rep(i,0,N-1) {
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // dfs를 통해 각 노드의 depth값과 부모 노드를 찾음
    nodes[1][0] = 1;
    nodes[1][1] = 1;
    dfs(1,1);

    // rep(i,1,N+1) {
    //     printf("node %d [parents:%d depth:%d]\n", i, nodes[i][0], nodes[i][1]);
    // }

    // 공통부모 찾기 쿼리 수행
    int M;
    scanf("%d", &M);
    rep(i,0,M) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", parentquery(a,b));
    }

    return 0;
}

void dfs(int curnode, int depth) {

    // 현재 노드부터 시작하는 자식노드 탐색
    for (int next : graph[curnode]) {
        if (nodes[next][1] != 0) continue;      // 이미 방문함
        nodes[next][0] = curnode;
        nodes[next][1] = depth+1;
        dfs(next, depth+1);
    }
}

int parentquery(int a, int b) {
    // depth가 같아질 때까지
    while(nodes[a][1] != nodes[b][1]) {
        if (nodes[a][1] < nodes[b][1]) b = nodes[b][0];
        else a = nodes[a][0];
    }

    // 두 노드 포인터가 만날 때까지 
    while(a != b) {
        a = nodes[a][0];
        b = nodes[b][0];
    }
    return a;
}