#include <stdio.h>
#include <math.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
  int T;
  scanf("%d", &T);
  rep(i,1,T+1) PS(i);
  
  return 0;
}

// 두 수로 index의 수를 만들 수 있는 경우의 수
int twosum[200001] = {0}; 

void PS(int TCnum) {
  int N, K;
  scanf("%d %d", &N, &K);
  rep(i,1,N*2+1) {
    // 각 수를 만드는 경우의 수의 해를 구하는 식
    twosum[i] = N - abs((N+1)-i);
    // printf("%d ", twosum[i]);
  }

  long long ans = 0;
  rep(i,0,N*2+1) {
    if (i+K <= 0 || i+K > N*2 ) continue;
    ans += 1LL * twosum[i] * twosum[i+K];
  }

  printf("%lld\n", ans);
}