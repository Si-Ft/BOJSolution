#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

/*
  접근법 : 꽂혀있는 플러그들 중 다음 꽂는 플러그가 가장 멀리 있는 걸 고른다.
  근데 다음 플러그까지 거리를 미리 계산하는 방식을 쓰니 너무 복잡해졌음.
  결국 플러그를 뽑아야 하는 순간마다 for문돌려서 계산

  N,K의 최대값을 10,000까지 올려도 풀 수 있을듯. (해당 풀이로는 숫자 커지면 못품)
*/
int main() {
    int N,K;    // 멀티탭 구멍 수, 전기용품 수
    scanf("%d %d",&N,&K);

    int seq[101];
    rep(i,0,K) scanf("%d", &seq[i]);

    bool plug[101] = {false,};
    int plugcount = 0;
    int unplugcount = 0;

    rep(i,0,K) {
        if(plug[seq[i]]) continue;

        // 꽂을 공간이 있다면 그냥 꽂는다.
        if(plugcount < N) {
            plug[seq[i]] = true;
            plugcount++;
            continue;
        }

        // 가장 나중에 사용되는 전기용품 찾음
        int idx = -1;
        int maxidx = -1;
        rep(j,0,K) {
            if(plug[seq[j]]) {
                int k;
                for(k=i+1;k<K;k++) {
                    if(seq[j] == seq[k]) break;
                }
                if(k > maxidx) {
                    maxidx = k;
                    idx = seq[j];
                }
            }
        }

        plug[idx] = false;
        plug[seq[i]] = true;
        unplugcount++;
    }
    printf("%d\n", unplugcount);
}