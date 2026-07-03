#include <stdio.h>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    vector<int> v[200001];
    int depth[200001] = {0};
    int N;
    scanf("%d", &N);

    rep(i,2,N+1) {
        int p;
        scanf("%d", &p);
        v[p].push_back(i);
    }

    queue<int> q;
    depth[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int child : v[cur]) {
            depth[child] = depth[cur] + 1;
            q.push(child);
        }
    }
}