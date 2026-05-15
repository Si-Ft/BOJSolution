// 코딩테스트 연습 >> Summer/Winter Coding(~2018) >> 배달
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;   // 현재 거리, 노드 번호

// 다익스트라인데, 1번 기준 거리 초과 시, 애초에 끊긴 노드로 판정
int solution(int N, vector<vector<int>> road, int K) {
    int graph[51][51] = {0}; // 그래프 정보
    bool visited[51] = {false}; // 방문 여부
    int answer = 0;

    for (vector<int> cr : road) {
        // 도로 정보가 초기화되어있지 않거나, 이미 있는데 현재 도로가 더 효율적인 경우
        if (graph[cr[0]][cr[1]] == 0 || graph[cr[0]][cr[1]] > cr[2]) {
            graph[cr[0]][cr[1]] = cr[2];
            graph[cr[1]][cr[0]] = cr[2];
        }
    }
    // 다익스트라 시작, 시작점은 1번 마을
    pq.emplace(0, 1);
    while(!pq.empty()) {
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (visited[curNode]) continue; // 이미 방문한 노드, 방문처리
        visited[curNode] = true;
        if (curDist > K) continue; // 거리 초과
        answer++;

        for (int i=1; i<=N; i++) {
            if (graph[curNode][i] == 0) continue; // 연결된 도로가 없는 경우
            pq.emplace(curDist + graph[curNode][i], i);
        }
    }

    return answer;
}