#include <stdio.h>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int preConnectedNode[32001] = {0,};

int N,M;
vector<vector<int>> compSeq(32001);
priority_queue<int, vector<int>, greater<int>> nextSearch;

void traversal();

int main() {
    scanf("%d %d", &N, &M);
    rep(i,0,M) {
        int A,B;
        scanf("%d %d", &A, &B);
        preConnectedNode[B]++;
        compSeq[A].push_back(B);
    }

    traversal();

    return 0;
}

void traversal() {
    rep(i,1,N+1) {
        if (preConnectedNode[i] != 0) continue;
        nextSearch.push(i);
    }

    while(!nextSearch.empty()) {
        int curNode = nextSearch.top();
        printf("%d ", curNode);
        nextSearch.pop();

        for (int nextNode : compSeq[curNode]) {
            preConnectedNode[nextNode]--;
            if (preConnectedNode[nextNode] == 0) nextSearch.push(nextNode);
        }
    }
}