#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[1001];
queue<int> Q;
bool visited[1001];

void DFS(int k);
void BFS(int k);

int main(){
    int N,M,V;
    int a,b;
    scanf("%d %d %d",&N,&M,&V);
    for (int i=0;i<M;i++) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=0;i<1001;i++) visited[i]=false;
    DFS(V); 
    printf("\n");
    for (int i=0;i<1001;i++) visited[i]=false;
    BFS(V);
}

void DFS(int k) {
    if (visited[k]) return;
    visited[k]=true;
    printf("%d ",k);
    sort(v[k].begin(),v[k].end());
    for (int i=0;i<v[k].size();i++) DFS(v[k][i]);
}

void BFS(int k) {
    int t;
    if (visited[k]) return;
    visited[k]=true;
    printf("%d ",k);
    sort(v[k].begin(),v[k].end());
    for (int i=0;i<v[k].size();i++) Q.push(v[k][i]);
    while(Q.size()) {
        t=Q.front();
        Q.pop();
        BFS(t);
    }
}