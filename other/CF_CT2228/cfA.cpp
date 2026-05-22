#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    int N;
    int nums[3] = {0}; // 0,1,2의 개수
    scanf("%d", &N);
    rep(i,0,N) {
        int x;
        scanf("%d", &x);
        nums[x]++;
    }

    int ans = nums[0];
    int ans2 = std::min(nums[1], nums[2]);
    ans += ans2;
    nums[1] -= ans2;
    nums[2] -= ans2;

    if (nums[1] > 0) ans += nums[1]/3;
    if (nums[2] > 0) ans += nums[2]/3;

    printf("%d\n", ans);
}