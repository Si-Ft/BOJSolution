#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int nums[1001];
int sorted[1001];
int moveNum[3][3] = {0}; // i->j번 자리로 가야하는 숫자의 수

int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) {
        scanf("%d", nums + i);
        sorted[i] = nums[i];
    }
    sort(sorted, sorted + N);

    int needSwap = 0;   // 제자리를 못 찾은 숫자들의 개수
    int ans = 0;        // 총 스왑 횟수
    rep(i,0,N) {
        if (nums[i] == sorted[i]) continue;     // 이미 제자리에 있음
        moveNum[nums[i] - 1][sorted[i] - 1]++;  // i번째 인덱스의 숫자가 가야 할 제자리 범위
        needSwap++;
    }

    // 한 번의 swap으로 두 수가 동시에 제자리를 찾을 수 있는 경우
    ans += min(moveNum[0][1], moveNum[1][0]); // 1<->2 스왑 횟수
    ans += min(moveNum[0][2], moveNum[2][0]); // 1<->3 스왑 횟수
    ans += min(moveNum[1][2], moveNum[2][1]); // 2<->3 스왑 횟수
    needSwap -= 2*ans;      // 1회 스왑 = 2개의 제자리 찾은 숫자

    // 나머지는 스왑을 2회 해서 3개의 수를 제자리로 돌리는 경우
    ans += needSwap*2/3;

    printf("%d", ans);
    return 0;
}