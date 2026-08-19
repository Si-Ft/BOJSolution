#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 999;

    int conn[101] = {0};        // 노드 추가 시 연결된 간선의 개수
    vector<vector<int>> e(101); // 간선 정보

    // idx N : 송전탑의 번호 | value : 본인 포함 leaf쪽 노드 개수
    // 해당 위치의 노드를 본다는 것 = 부모 쪽 간선을 끊었을 때 나뉘는 노드
    int ninfo[101] = {0};
    bool visited[101] = {false};

    for (vector<int> wire : wires) {
        e[wire[0]].push_back(wire[1]);
        e[wire[1]].push_back(wire[0]);
        conn[wire[0]]++;
        conn[wire[1]]++;
    }

    queue<int> q;   // 탐색할 노드 순서, 노드 순회 초기화
    rep(i,1,n+1) if (conn[i] == 1) q.push(i);

    while(!q.empty()) {
        // 현재 노드 탐색 시 방문처리를 통해 ninfo 배열 잠금
        int cn = q.front();
        ninfo[cn]++;
        visited[cn] = true;
        q.pop();

        // 주변 모든 노드들 확인 (부모는 유일하게 하나이므로 발견 시 break)
        for (int nn : e[cn]) {
            if (visited[nn]) continue;
            ninfo[nn] += ninfo[cn];
            conn[cn]--;
            conn[nn]--;
            if (conn[nn] == 1) q.push(nn); 

            break;
        }
    }

    // 모든 노드의 부모방향 간선을 잘랐을 때, 양 쪽의 노드 개수의 차이의 최소값을 answer에 계속 갱신
    rep(i,1,n+1) {
        int ret = min(ninfo[i], n-ninfo[i]);
        answer = min(answer, n-2*ret);
    }

    return answer;
}