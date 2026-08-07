#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> gmap;    // 장르명과 내부 인덱스를 매핑

    // 각 장르 인덱스 별 총 플레이 수 (idx : 장르 내부 인덱스)
    // 추후 정렬을 위해 2번째 인자로 장르 내부 인덱스를 함께 저장
    vector<pair<int,int>> gplay;

    // 장르별 노래 목록 <play수, 노래 번호>
    vector<vector<pair<int,int>>> gsongs;

    int gidx = 0;
    for (int i=0; i<plays.size(); i++) {
        // gmap에 장르명과 내부 인덱스 매핑
        if (gmap.find(genres[i]) == gmap.end()) {
            gmap[genres[i]] = gidx;
            gplay.push_back(make_pair(0, gidx));
            gsongs.push_back(vector<pair<int,int>>());
            gidx++;
        }

        int idx = gmap[genres[i]];
        // 플레이 카운트 등록
        gplay[idx].first += plays[i];
        // 장르별 노래 목록 등록
        gsongs[idx].push_back(make_pair(plays[i], i));
    }

    // play 수 내림차순으로 정렬
    sort(gplay.begin(), gplay.end(), greater<pair<int,int>>());

    for (int i=0; i<gplay.size(); i++) {
        int idx = gplay[i].second;
        // 장르별 노래 목록을 play 수 내림차순으로 정렬
        // 단, 플레이 수가 같을 경우 노래 번호 오름차순으로 정렬
        sort(gsongs[idx].begin(), gsongs[idx].end(), [](pair<int,int> a, pair<int,int> b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        // 장르별 상위 2곡만 answer에 추가
        for (int j=0; j<gsongs[idx].size() && j<2; j++) {
            answer.push_back(gsongs[idx][j].second);
        }
    }

    return answer;
}