#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long lp = 0, rp = 1LL<<62; // 가능한 심사 시간

    while(lp < rp) {
        long long mid = (lp+rp)/2;
        long long leftn = n;
        bool isPos = false;      // 가능 불가능 여부

        for (int t : times) {
            leftn -= mid / t;   // 단위 심사 공간 당 수용가능한 인원 수를 뺌
            if (leftn <= 0) {isPos = true; break;}
        }
        if (isPos) rp = mid;
        else lp = mid+1;
    }

    return rp;
}