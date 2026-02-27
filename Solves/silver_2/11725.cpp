#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int momNode[100001]={0,100001,0,};
vector<vector<int>> nodeLine;

void tree_traverse(int nodeNum);

int main() {
    int N;
    scanf("%d", &N);
    nodeLine.resize(N+1);

    for (int i=0;i<N-1;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        nodeLine[a].push_back(b);
        nodeLine[b].push_back(a);
    }
    tree_traverse(1);
    for (int i=2;i<=N;i++) printf("%d\n", momNode[i]);
    return 0;
}

void tree_traverse(int nodeNum){
    for (;nodeLine[nodeNum].size();) {
        int sonNode = *(nodeLine[nodeNum].end()-1);
        if (!momNode[sonNode]) {
            momNode[sonNode] = nodeNum;
            tree_traverse(sonNode);
        }
        nodeLine[nodeNum].pop_back();
    }
}