#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<pair<int,int>> p;        // <석차, 참가자 번호>
    for (int i=0; i<rank.size();i++) {
        if (attendance[i]) {
            p.push_back({rank[i], i});
        }
    }
    sort(p.begin(), p.end());
    
    for (int i=0; i<3; i++) {
        answer = answer * 100 + p[i].second;
    }
    return answer;
}