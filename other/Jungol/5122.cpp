#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N, M, Q;    // 상품의 개수, 상품 종류의 수, 손님의 수
    scanf("%d %d %d", &N, &M, &Q);

    vector<long long> psum;   // 모든 상품의 가격 누적합 배열

    /*  상품 종류별 가격 누적합 배열
        바깥쪽 vector idx = 상품 종류 번호
        안쪽 vector value = <psum 배열의 인덱스, 상품 종류별 가격 누적합>
    */ 
    vector<vector<pair<int,long long>>> dsum(M+1, {{0, 0}});
    psum.push_back(0);

    rep(i,0,N) {
        int p, a;    // 상품의 가격, 상품의 종류
        scanf("%d %d", &p, &a);
        psum.push_back(psum.back() + p);
        dsum[a].push_back({i+1, dsum[a].back().second + p});
    }

    rep(i,0,Q) {
        int c,l,r;    // 할인이 적용되는 카테고리, 구매한 상품의 시작 번호, 끝 번호
        scanf("%d %d %d", &c, &l, &r);
        long long oprice = psum[r] - psum[l-1];    // 할인 적용 전 가격

        // l,r 범위의 상품 중 c 카테고리의 상품 가격 합
        auto it1 = lower_bound(dsum[c].begin(), dsum[c].end(), make_pair(l, 0LL));
        auto it2 = lower_bound(dsum[c].begin(), dsum[c].end(), make_pair(r+1, 0LL));
        long long dprice = (it2-1)->second - (it1-1)->second;    // 할인 적용 후 가격
                
        printf("%lld\n", oprice - dprice/2);
    }

    return 0;
}