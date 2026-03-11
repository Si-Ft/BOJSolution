#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

bool compare(int a, int b) { return a > b; }

int main() {
    int tc;
    scanf("%d", &tc);
    rep(K,0,tc) {
        int n,c,l;
        scanf("%d %d %d", &n, &c, &l);

        int livingPoint[501][2] = {0}; // 0은 취함(I), 1은 안취함(S)
        rep(i,0,n) {
            int rn;
            char drunk;
            scanf("%d %c", &rn, &drunk);
            if (drunk == 'I') drunk=0;
            else drunk=1;
            livingPoint[rn][drunk] += 1;
        }

        int tot=n;
        vector<vector<int>> car(501);
        rep(i,0,c) {
            int rn, seats;
            scanf("%d %d", &rn, &seats);
            car[rn].push_back(seats);
        }

        rep(i,1,l+1) {
            // 각 지역을 대상으로 하는 차들을 정렬
            sort(car[i].begin(), car[i].end(), compare);

            // 차 공간이 많은 순서대로 사람들을 태움.
            for (int j : car[i]) {
                // printf("t - %d %d %d %d\n", tot, i, j, livingPoint[i][1]);
                if (livingPoint[i][1] <= 0) continue;

                
                // 술 안취한 사람 1명 태움
                livingPoint[i][1]--;
                j--;
                tot--;

                // 술 취한 사람 전원 탑승
                int topseung = min(j,livingPoint[i][0]);
                livingPoint[i][0] -= topseung;
                j -= topseung;
                tot -= topseung;

                // 남은 자리가 있다면, 안 취한 사람 탑승
                if (j==0) continue;
                topseung =  min(j,livingPoint[i][1]);
                livingPoint[i][1] -= topseung;
                j -= topseung;
                tot -= topseung;
            }
        }

        printf("Data Set %d:\n%d\n", K+1,tot);
    }
    return 0;
}