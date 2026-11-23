#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N, M;   // 아이의 수, 색상의 수
    scanf("%d %d", &N, &M);
    int arr[300000];
    rep(i,0,M) scanf("%d", &arr[i]);

    // l은 가능한 최소 값, r은 가능한 최대 값
    int l=1, r=1000000000;
    while(l < r) {
        int mid = (l+r)/2;
        int count = 0;
        rep(i,0,M) {
            count += (arr[i]/mid) + ((arr[i]%mid != 0)?1:0);
        }
        if (count > N) l = mid+1;
        else r = mid;
    }

    printf("%d", l);

    return 0;
}