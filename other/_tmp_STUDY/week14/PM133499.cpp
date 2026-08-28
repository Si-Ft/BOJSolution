#include <string>
#include <vector>

using namespace std;

vector<string> words = {"aya", "ye", "woo", "ma"};
int solution(vector<string> babbling) {
    int answer = 0;

    for (string str : babbling) {
        string before;
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];

            // 첫 부분을 기준으로 단어가 일치하면 제거
            if (str.find(w) == 0) {
                if (before == w) break;
                str.erase(0, w.length());
                before = w;
                i = -1;
            }
        }
        if (str.empty()) {
            answer++;
        }
    }

    return answer;
}