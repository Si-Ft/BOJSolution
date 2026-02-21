#include <stdio.h>
#include <vector>
using namespace std;

int main() {

    // N개의 왕복 간선을 넣는 코드

    vector<vector<int>> nodeLine;
    int N;
    scanf("%d", &N);

    for (int i=0;i<N;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        nodeLine[a].push_back(b);
        nodeLine[b].push_back(a);
    }

    // 여기까지
    
}