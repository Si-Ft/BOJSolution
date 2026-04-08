#include <stdio.h>
#include <queue>
#include <stdlib.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,k;
int road[100000][2];
int dist[100000][2] = {0};
queue<int> nextSearch;

int main() {
    scanf("%d %d", &N, &k);
    char a;
    rep(i,0,N) {
        scanf(" %c", &a);
        road[i][0] = a-'0';
    }
    rep(i,0,N) {
        scanf(" %c", &a);
        road[i][1] = a-'0';
    }
    dist[0][0] = 1;
    nextSearch.push(0);

    while(!nextSearch.empty()) {
        int st = nextSearch.front() % 100000;
        int lr = nextSearch.front() / 100000;
        //printf("popped : %d %d %d\n", st, lr, dist[st][lr]);
        nextSearch.pop();

        // 0일 경우 1, 1일 경우 -1

        int dst[3] = {1,-1,k};
        int dlr[3] = {0,0,-1*(lr*2-1)};
        rep(i,0,3) {
            int cst = st + dst[i];
            int clr = lr + dlr[i];

            if (cst<0) continue;
            if (cst>=N) {
                printf("1");
                return 0;
            }
            if (road[cst][clr] == 0) continue;
            if (dist[cst][clr] != 0) continue;

            dist[cst][clr] = dist[st][lr] + 1;
            if (dist[cst][clr] > cst+1) continue;
            nextSearch.push(cst+clr*100000);
        }
    }
    printf("0");
    return 0;
}

