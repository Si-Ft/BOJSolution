#include <string>
#include <vector>

using namespace std;

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