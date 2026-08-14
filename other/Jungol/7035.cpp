#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

const int tsize = 1<<17;
/*  점수 분포 구간 개수 합 세그먼트 트리 
    (value : 해당 점수에 할당되어있는 학생의 수)
    idx 131072가 0점에 해당하는 학생의 수
*/
int scoreDistrib[1<<18] = {0};
int studScore[100001] = {0};        // idx: 학생 번호 | value: 학생의 점수

// targetscore의 개수를 증가시키거나(diff=1), 감소시킴(diff=-1);
void treeUpdate(int targetscore, int diff) {
    int idx = tsize+targetscore;
    // 트리를 타고 올라가면서 점수 개수합의 변화량을 전부 기록
    while(idx) {
        scoreDistrib[idx] += diff;
        idx /= 2;
    }
}

int treeQuery(int qs, int qe, int cs, int ce, int tidx) {
    if (qs <= cs && qe >= ce) return scoreDistrib[tidx];
    if (ce < qs || cs > qe ) return 0;

    int mid = (cs+ce)/2;
    return treeQuery(qs,qe,cs,mid,tidx*2) + treeQuery(qs,qe,mid+1,ce,tidx*2+1);
}

int main() {
    int N,Q;
    scanf("%d %d",&N,&Q);
    rep(i,1,N+1) {
        int s;
        scanf("%d", &s);
        studScore[i] = s;
        scoreDistrib[tsize+s]++;
    }

    // 트리 초기화
    rrep(i,tsize-1,1) {
        scoreDistrib[i] = scoreDistrib[i*2] + scoreDistrib[i*2+1];
    }

    // 쿼리 입력받음
    rep(i,0,Q) {
        int c,x,y;
        scanf("%d %d", &c, &x);
        if (c==1) printf("%d\n", treeQuery(studScore[x]+1,tsize-1,0,tsize-1,1) + 1);
        else {
            scanf("%d", &y);
            treeUpdate(studScore[x], -1);
            treeUpdate(y, 1);
            studScore[x] = y;
        }
    }


    return 0;
}