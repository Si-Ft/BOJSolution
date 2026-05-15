// 코딩테스트 연습 >> 해시 >> 의상
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    vector<string> dict;

    int answer = 1;
    // 각 옷의 정보에 대해서 (들어있는 값은 각각 옷의 이름, 옷의 종류)
    for (vector<string> vs : clothes) {
        if (m.find(vs[1]) == m.end()) dict.push_back(vs[1]);
        m[vs[1]]++; // 옷의 개수만 카운트하면 됨.
    }

    for (string type : dict) {
        answer *= (m[type] + 1);
    }

    return answer - 1;
}