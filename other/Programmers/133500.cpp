#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
/*
    뱃길이 n-1개만큼 존재하며 모든 등대가 이어짐 == Tree 조건을 만족
    Tree조건은 leaf노드가 있음. 즉, leaf노드를 기준으로 leaf노드와 이어진 노드를 최우선으로 불을 밝힘
    
    그냥 아무 노드나 루트로 잡고 (그것이 leaf여도 상관없음) 
    연결된 노드들을 이용해 dfs 수행. (parent 제외) 
    각 dfs함수의 끝엔 현재 노드의 dp배열을 계산할 것임. 
    (자식노드들의 dp배열이 최종 확정됨) 
    
    점화식은 
    1) dp[node][0] = sum(dp[자식노드들][1]) 
    2) dp[node][1] = sum(min(dp[자식노드들][0] or [1])) + 1 
    3) 자식노드들이 없다면 자연스럽게 1)은 0, 2)은 1이 됨. 
    
    최종적으로 루트노드의 dp의 [0], [1] 중 작은 것이 정답.
*/
void dfs(int curNode, int parents);

vector<vector<int>> boatPath(100001);  // 노드 -> 다음노드로 가는 길
int dp[100001][2] = {0};      
// [등대 번호][0:끔, 1:켬] 
// value : idx의 조건일 때, 켠 등대 최소 개수

int solution(int n, vector<vector<int>> lighthouse) {
    for (vector<int> lh : lighthouse) {
        // 노드를 기준으로 양방향 노드를 추가
        boatPath[lh[0]].push_back(lh[1]);
        boatPath[lh[1]].push_back(lh[0]);
    }

    int startNode;  // 탐색을 시작할 노드 (단, leaf노드가 아닐 것)
    for (int i=1; i<=n; i++) {
        if (boatPath[i].size() != 1) {
            startNode = i;
            break;
        }
    }
    dfs(1,0);
    return min(dp[1][0], dp[1][1]);
}

void dfs(int curNode, int parents) {
    for (int nnode : boatPath[curNode]) {
        if (nnode == parents) continue; // dfs 역주행 방지
        dfs(nnode, curNode);    // dfs 수행하고 나면, dp배열에 올바른 값이 들어감이 보장됨
        dp[curNode][0] += dp[nnode][1];
        dp[curNode][1] += min(dp[nnode][0], dp[nnode][1]);
    }
    dp[curNode][1]++;   // 현재 노드를 켰으므로, 총 개수 추가
}