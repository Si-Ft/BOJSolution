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

    vector<int> nums(N, 0);   // 해당 숫자의 등장 횟수
    rep(i,0,N) {
        int x;
        scanf("%d", &x);
        nums[x]++;
    }

    vector<int> heights(N+1,0);
    for (int i=N-1; i>0; i--) {
        heights[i] = heights[i+1] + nums[i];
    }
}