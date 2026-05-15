// 코딩테스트 연습 >> 깊이/너비 우선 탐색(DFS/BFS) >> 타겟 넘버
#include <string>
#include <vector>
using namespace std;

int answer;
int tg;

void dfs(const vector<int>& numbers, int curVal, int depth) {
    if (depth == numbers.size()) {
        if (curVal == tg) answer++;
        return;
    }

    dfs(numbers, curVal + numbers[depth], depth+1);
    dfs(numbers, curVal - numbers[depth], depth+1);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    tg = target;
    dfs(numbers, 0, 0);
    return answer;
}