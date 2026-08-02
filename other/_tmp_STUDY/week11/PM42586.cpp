#include <string>
#include <vector>

using namespace std;

/*
  분류 자체는 스택/큐로 분류되지만, 사실상 구현 문제에 가까움
  스택 대신 idx를 이용해서 구현하는 방법으로 풀었습니다.
*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int N = progresses.size();
    int day = 0;
    int idx = 0;
    while(true) {
      int task = 0;
      day++;

      while (idx < N && (progresses[idx] + speeds[idx]*day) >= 100) {
        task++;
        idx++;
      }
      if (task) answer.push_back(task);
      if (idx >= N) break;
    }

    return answer;
}