#include <stdio.h>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

// 특정 번호 앞에서 먼저 줄 서야하는 사람의 수
int preConnectedNode[1001] = {0,};

int N,M;
vector<vector<int>> compSeq(1001);
bool visited[1001] = {false};
vector<int> ansSeq;
queue<int> nextSearch;

int traversal();

int main() {
    scanf("%d %d", &N, &M);
    rep(i,0,M) {
        int A,B,seq;
        scanf("%d %d", &seq, &A);
        rep(j,1,seq) {
            scanf("%d", &B);
            preConnectedNode[B]++;
            compSeq[A].push_back(B);
            A = B;
        }
    }

    if (traversal()) printf("0");
    else if (ansSeq.size() != N) printf("0");
    else for (int i : ansSeq) printf("%d\n", i);

    return 0;
}

int traversal() {
    rep(i,1,N+1) {
        if (preConnectedNode[i] != 0) continue;
        nextSearch.push(i);
    }

    while(!nextSearch.empty()) {
        int curNode = nextSearch.front();
        ansSeq.push_back(curNode);
        nextSearch.pop();
        // 사이클이 있는 경우
        if (visited[curNode]) return 1;
        visited[curNode] = true;

        for (int nextNode : compSeq[curNode]) {
            preConnectedNode[nextNode]--;
            if (preConnectedNode[nextNode] == 0) nextSearch.push(nextNode);
        }
    }
    return 0;
}