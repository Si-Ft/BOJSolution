#include <stdio.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<int> v;
vector<int> xIndex;
int count[300001] = {0};

int maxNum = 0; // 빈도가 가장 높은 음식의 종류
int CandidateMaxNum = 0; // 빈도가 가장 높은 음식의 종류 후보

int main() {
    int N;
    scanf("%d", &N);
    rep(i, 0, N) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
        count[x]++;
    }

    // 가장 많이 나온 음식의 종류 x 찾기 (x <= N)
    int maxCount = 0;
    rep(i, 0, N+1) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxNum = i;
            CandidateMaxNum = 0;
        }
        else if (count[i] == maxCount) {
            CandidateMaxNum = i;
        }
    }

    // 최대 빈도 숫자가 2개 존재할 경우, v에서 가장 먼저 나오는 숫자 찾기
    if (CandidateMaxNum != 0) {
        rep(i, 0, N) {
            if (v[i] == maxNum || v[i] == CandidateMaxNum) {
                maxNum = v[i];
                break;
            }
        }
    }


    // maxNum의 절대 index 리스트 만들기
    rep(i, 0, N) {
        if (v[i] == maxNum) {
            xIndex.push_back(i);
        }
    }



    return 0;
}