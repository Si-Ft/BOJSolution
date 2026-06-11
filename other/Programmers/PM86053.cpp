#include <string>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

bool isCanBuild(long long time);
int towns;
long long A,B;
vector<int> G;
vector<int> S;
vector<int> W;
vector<int> T;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    G = g; S = s; W = w; T = t;
    A = a; B = b; towns = g.size();

    long long lp = 0, rp = __LONG_LONG_MAX__ / 256;
    while(lp < rp) {
        long long mid = (lp + rp) / 2;
        if (isCanBuild(mid)) rp = mid;
        else lp = mid + 1;
    }

    return rp;
}

// 제한 시간에 건축 가능한지 여부
bool isCanBuild(long long time) {
    long long maxCap = 0;       // 전체 광물 가능량
    long long maxGold = 0;      // 최대 금 가능량
    long long maxSilver = 0;    // 최대 은 가능량

    rep(i,0,towns) {
        // 왕복 가능 수
        long long maxTimes = (time / T[i] + 1) / 2;

        // 최대 광물 가능량 체크
        maxCap += min((long long)G[i] + S[i], (long long)W[i]*maxTimes);
        maxGold += min((long long)G[i], (long long)W[i]*maxTimes);
        maxSilver += min((long long)S[i], (long long)W[i]*maxTimes);
    }

    if (A+B > maxCap) return false;
    if (A > maxGold) return false;
    if (B > maxSilver) return false;

    return true;
}