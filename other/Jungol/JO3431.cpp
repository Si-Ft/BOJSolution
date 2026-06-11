#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct LG {
    int x1, x2;
    int num;
};  // 통나무 정보

int ds[100001] = {0,};  // 이동 가능한 통나무 집합
vector<LG> lgs;

int LGcomp(LG a, LG b) {
    return a.x1 < b.x1;
}

int main() {
    int N,Q;    // 통나무 수, 쿼리의 수
    scanf("%d %d", &N, &Q);
    rep(i,1,N+1) {
        ds[i] = i;
        LG inp;
        scanf("%d %d %d", &inp.x1, &inp.x2, &inp.num);
        inp.num = i;    // y좌표는 의미 없음
        lgs.push_back(inp);
    }

    // 통나무 시작지점 기준으로 정렬
    sort(lgs.begin(), lgs.end(), LGcomp);
    int rmost = -1;  // 커버가능한 범위
    int head = 0;   // 대표가 될 통나무 번호
    for (LG clg : lgs) {
        if (clg.x1 > rmost) {   // 새로운 집합 시작
            head = clg.num;
            rmost = clg.x2;
            continue;
        }
        // 이전 통나무와 겹치는 경우
        rmost = max(rmost, clg.x2);
        ds[clg.num] = head;     // 대표 통나무 번호를 이용한 집합 생성
    }

    rep(i,0,Q) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);

        // 대표 통나무 번호가 같다 == 이어져있는 통나무 길이다.
        if (ds[n1] == ds[n2]) printf("1\n");
        else printf("0\n");
    }

    return 0;
}