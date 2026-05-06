#include <stdio.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    int N;
    scanf("%d", &N);

    vector<int> nums;
    int count[200001] = {0}; // 숫자 등장 횟수 저장
    for (int i=0; i<2*N; i++) {
        int x;
        scanf("%d", &x);
        nums.push_back(x);
    }

    // 투 포인터 이용해서 팰린드롬 찾기
    int l=0, r=0, bad = 0; // bad는 count[x] == 1인 숫자의 개수
    while (r < 2*N) {
        count[r]++;
        if (count[r] == 1) bad++; // 새로운 숫자 등장
        if (count[r] == 2) bad--; // 숫자가 두 번 등장, 팰린드롬 조건 만족

        if (bad >= 2) { // 팰린드롬 조건 불만족
            
        }
    }
}