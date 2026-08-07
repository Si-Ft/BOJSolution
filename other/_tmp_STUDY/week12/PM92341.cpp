#include <string>
#include <vector>

using namespace std;

int calfee(vector<int> f, int t);

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int carstat[10000][3] = {0};        // idx: 차번호 | 0 : 방문여부 | 1 : 최근 입차 시간 | 2 : 누적 시간
    for (string r : records) {
        // records 문자열로부터 정보 빼오기
        int time = stoi(r.substr(0,2)) * 60;
        time += stoi(r.substr(3,2));
        int cn = stoi(r.substr(6,4));
        carstat[cn][0] = 1;

        if (r.substr(11, 2) == "IN") {
            carstat[cn][1] = time + 1; 
        }
        else {
            // 출차 시 누적 시간 기록
            carstat[cn][2] += (time + 1 - carstat[cn][1]);
            carstat[cn][1] = 0;
        }
    }

    // 출력
    for (int i=0; i<10000; i++) {
        if (carstat[i][0] != 1) continue;
        if (carstat[i][1] > 0) carstat[i][2] += (1440 - carstat[i][1]);
        answer.push_back(calfee(fees, carstat[i][2]));
    }

    return answer;
}

// fees | 0 = 기본 시간 | 1 = 기본 요금 | 2 = 단위 시간 | 3 = 단위 요금
int calfee(vector<int> f, int t) {
    t -= f[0];
    if (t <= 0) return f[1];
    return f[1] + (t + f[2] - 1) / f[2] * f[3];
}