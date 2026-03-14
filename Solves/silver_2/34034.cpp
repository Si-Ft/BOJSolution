#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> pb;
int main() {
    int N,M,K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i=0;i<N;i++) {
        int inp;
        scanf("%d", &inp);
        pb.push_back({inp, i+1});
    }

    sort(pb.begin(), pb.end());

    int tot=0;
    for (int i=0;i<(K-M);i++) {
        if (i>=N) {
            printf("-1");
            return 0;
        }
        tot += pb[i].first;
        if (tot > K) {
            printf("-1");
            return 0;
        }
    }

    int curPB = -1;
    int leftPB = -1;
    for (int i=0;i<K;i++) {
        if (leftPB <= 0) {
            curPB++;
            if (curPB >= N) leftPB = __INT_MAX__;
            else leftPB = pb[curPB].first;
        }
        leftPB--;
        if (leftPB <= 0) printf("%d ", pb[curPB].second);
        else printf("0 ");
    }

    return 0;
}