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

// 현재까지 각 열쇠 보유량에 따른 경우의 수 DP배열
int keys[51];

// 간선의 정보 (값1: 목적지, 값2: 통로개방 여부)
vector<vector<pair<int,int>>> v(51);

void PS(int TCnum) {
    rep(i,0,51) {
        keys[i] = 0;
    }

}