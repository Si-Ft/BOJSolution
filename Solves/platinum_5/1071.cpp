// P5
#include <stdio.h>
#include <algorithm>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int A[51];
// A[i] = (값, 개수)
vector<pair<int, int>> indepA;
vector<int> ans;

void arraySwap(int begin, int end);

int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) scanf("%d", &A[i]);
    sort(A, A+N);

    rep(i,0,N) {
        if (i == 0 || A[i] != A[i-1]) {
            int count = 1;
            while (i+1 < N && A[i+1] == A[i]) {
                count++;
                i++;
            }
            indepA.push_back({A[i], count});
        }
    }
    int before = -2;
    // 여기까지 indepA는 정렬된 수와 개수가 들어가 있음.
    while(!indepA.empty()) {
        auto curNum = indepA.front();
        auto nextNum = indepA[1];
        if (indepA.size() == 1) {
            for (int i = 0; i < curNum.second; i++) {
                ans.push_back(curNum.first);
            }
            break;
        }
        if (!ans.empty()) before = ans.back();
        int cur = curNum.first;
        int next = nextNum.first;

        // (이전 배열의 값과 무관하게) 현재 남은 수 종류가 2개밖에 없을 때
        if (indepA.size() == 2) {
            if (cur + 1 == next) {
                // cur과 next차이가 1 차이나면 >> next "전부" 출력
                rep(i,0,nextNum.second) ans.push_back(next);
                indepA.erase(indepA.begin()+1);
            }
            else {
                // cur과 next차이가 2 이상 차이나면 
                if (before + 1 == cur) {
                    // before + 1 == cur >> next "한 개" 출력
                    ans.push_back(next);
                    indepA[1].second--;
                    if (indepA[1].second == 0) indepA.erase(indepA.begin()+1);
                } else {
                    // 이외 >> 그냥 cur "한 개" 출력
                    ans.push_back(cur);
                    indepA[0].second--;
                    if (indepA[0].second == 0) indepA.erase(indepA.begin());
                }
            }
        }
        // 이외 (남은 수 종류 3개 이상)
        else {
            // before + 1 == cur >> next "한 개" 출력
            if (before + 1 == cur) {
                ans.push_back(next);
                indepA[1].second--;
                if (indepA[1].second == 0) indepA.erase(indepA.begin()+1);
            } else {
                // 이외 >> 그냥 cur "한 개" 출력
                ans.push_back(cur);
                indepA[0].second--;
                if (indepA[0].second == 0) indepA.erase(indepA.begin());
            }
        }
    }

    for (int num : ans) printf("%d ", num);
}
