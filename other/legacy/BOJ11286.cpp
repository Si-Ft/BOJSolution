#include <stdio.h>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

// pair value : 절댓값, 부호 (0:음수, 1:양수)
// 절댓값 오름차순으로, 동일하다면 음수가 더 앞으로 오도록 pq를 만듬
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;  

int main() {
    int N;
    scanf("%d", &N);

    rep(i,0,N) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            if (pq.empty()) printf("0\n");
            else {
                int buho = pq.top().second;
                int val = pq.top().first;
                pq.pop();
                if (buho == 0) printf("-%d\n", val);
                else printf("%d\n", val);
            }
        }
        else {
            if (x < 0) pq.push({-x, 0});
            else pq.push({x, 1});
        }
    }
    return 0;
}