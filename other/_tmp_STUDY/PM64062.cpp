#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    long long ans = 0;
    long long l=1, r=200000001;
    // 징검다리를 건널 수 있는 최대의 인원 수를 이분탐색으로 찾음
    while(l<r) {
        long long mid = (l+r)/2;
        long long cnt = 0;

        // 현재 인원수로 징검다리를 전부 건널 수 있는지 확인
        for(int i=0; i<stones.size(); i++) {
            if(stones[i]-mid <= 0) cnt++;
            else cnt = 0;
            if(cnt == k) break;
        }
        if(cnt == k) r = mid; // 현재 인원으로 불가능
        else {
            l = mid+1;
        }
    }

    return l;
}