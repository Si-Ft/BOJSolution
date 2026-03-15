#include <stdio.h>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

// 특정 번호 앞에서 먼저 줄 서야하는 사람의 수
int preConnectedNode[32001] = {0,};

int N,M;
vector<vector<int>> compHeight(32000);
queue<int> nextSearch;

void traversal();

int main() {
    scanf("%d %d", &N, &M);
    rep(i,0,M) {
        int A,B;
        scanf("%d %d", &A, &B);

        preConnectedNode[B]++;
        compHeight[A].push_back(B);
    }

    traversal();

    return 0;
}

void traversal() {
    // 큐에 더 앞에 서는 사람이 없는 사람 먼저 넣기
    rep(i,1,N+1) {
        if (preConnectedNode[i] != 0) continue;
        nextSearch.push(i);
    }

    while(!nextSearch.empty()) {
        int curNode = nextSearch.front();
        printf("%d ", curNode);
        nextSearch.pop();

        for (int nextNode : compHeight[curNode]) {
            preConnectedNode[nextNode]--;
            if (preConnectedNode[nextNode] == 0) nextSearch.push(nextNode);
        }
    }
}