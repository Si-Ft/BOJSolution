#include <stdio.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

// 너무 어려워서 AI한테 힌트 많이 받음 ㅠㅠ
// give up. 이 코드에 binary lifting을 통한 검색을 시도해보려고 했는데
// 답이 안생김.

// 각 노드마다 넣을 정보
struct Ninfo{
    int dist;       // 가장 가까운 사이클 노드와의 거리
    int cycleIdx;   // 사이클 배열에서의 index 번호 
            // (dist가 0이 아니라면 사이클에 가장 가까운 idx번호) 
    int cycleNum;   // 사이클 라벨 번호

    Ninfo(int d = 0, int idx = -1, int num = -1)
        : dist(d), cycleIdx(idx), cycleNum(num) {}
} nds[100001];

vector<vector<int>> cycles(1);     // 각 사이클 정보
int curcnum = -1;    // dfs 실행 시 만들 사이클 번호
int state[100001] = {0};    // 0-탐색전 | 1-탐색중 | 2-탐색완료
int iv[100001];
int nv[100001];

int nodedepth[100001] = {0};
vector<int> path;

int main() {
    // 학생의 수, 동영상의 개수, 남은 수업시간
    int N,K,M;
    scanf("%d %d %d", &N, &K, &M);

    // 학생들이 처음으로 본 동영상 번호
    rep(i,0,N) scanf("%d", iv + i);

    // 동영상 번호 별 다음 시청할 동영상
    rep(i,1,N+1) scanf("%d", nv + i);

    rep(i,1,N+1) {
        if (state[i] != 0) continue;

        nds[i] = dfs(i, 1);
    }
    
    return 0;
}

Ninfo dfs(int curnode, int depth) {
    // 이미 계산 완료된 노드 (dfs중지)
    if (state[curnode] == 2) {
        return nds[curnode];
    }

    // 사이클 만들기 시작 (dfs중지)
    if (state[curnode] == 1) {
        curcnum++;  // 새로운 사이클 번호 추가
        cycles.push_back({});   // 빈 사이클 메모리 allocate

        // 사이클 정보 추가
        rep(i,nodedepth[curnode]-1,path.size()) {
            cycles[curcnum].push_back(path[i]);
        }
        // int cyclesize = depth-nodedepth[curnode];

        Ninfo ret(-1,-1,-1);
        return ret;
    }

    // 탐색중 플래그
    state[curnode] = 1;
    nodedepth[curnode] = depth;
    path.push_back(curnode);

    // 다음 dfs 탐색 부분
    Ninfo ret = dfs(nv[curnode], depth+1);

    path.pop_back();
    state[curnode] = 2;

    if (ret.dist == -1) {
        // 사이클 리와인드
        Ninfo rret(0,depth-nodedepth[curnode],curcnum);
        nds[curnode] = rret;
        // 제자리로 돌아왔다면 0으로 그대로 리턴, 아직 리와인드중이라면 -1
        if (depth != nodedepth[curnode]) rret.dist = -1;

        return rret;
    }

    // 사이클 밖 프로세스
    ret.dist++;
    nds[curnode] = ret;
    return ret;
}