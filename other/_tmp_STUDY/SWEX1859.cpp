#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

void PS(int TCnum);

int main() {
  int T;
  scanf("%d", &T);
  rep(i,1,T+1) PS(i);
  
  return 0;
}

int nums[1000000];
void PS(int TCnum) {
  int N;
  scanf("%d", &N);
  rep(i,0,N) scanf("%d", &nums[i]);

  // 역순으로 보면서 최대값을 갱신하며 이익을 계산
  long long ans = 0;
  int maxv = 0;
  rrep(i,N-1,0) {
    if (nums[i] > maxv) maxv = nums[i];
    else ans += maxv - nums[i];
  }
  printf("#%d %lld\n", TCnum, ans);
}