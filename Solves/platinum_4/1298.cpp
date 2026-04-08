#include <stdio.h>
#include <math.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<int> edges[100];
int match[100];
bool visited[100];

bool dfs(int mouse);

int main() {
    int N,M;
    scanf("%d %d", &N, &M);

    rep(i,0,M) {
        int a,b;
        scanf("%d %d", &a, &b);
        edges[a-1].push_back(b-1);
    }

    rep(i,0,N) match[i] = -1;
    int ans = 0;
    rep(i,0,N) {
        rep(j,0,N) visited[j] = false;
        if (dfs(i)) ans++;
    }
    printf("%d", ans);

    return 0;
}

bool dfs(int laptop) {
    for (int stud : edges[laptop]) {
        if (visited[stud]) continue;
        visited[stud] = true;

        if (match[stud] == -1 || dfs(match[stud])) {
            match[stud] = laptop;
            return true;
        }
    }
    return false;
}