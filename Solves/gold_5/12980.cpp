#include <stdio.h>
#include <stack>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,S;
int ans = 0;
int arr[101] = {0};

vector<int> missNum;
vector<int> missAddr;
int usedAddr = 0;

void backtrack(int curAddr);
int arrScore();

int main() {
    scanf("%d %d", &N, &S);
    int dict[101] = {0};
    rep(i,0,N) {
        scanf("%d", arr+i);
        if (arr[i] != 0) dict[arr[i]] = 1;
        else missAddr.push_back(i);
    }
    rep(i,0,N) if (dict[i+1] == 0) missNum.push_back(i+1);
    backtrack(0);
    printf("%d", ans);

    return 0;
}

void backtrack(int curAddr) {
    if (curAddr >= missNum.size()) {
        if (arrScore() == S) ans++;
        return;
    }
    rep(i,0,missNum.size()) {
        if ((usedAddr & 1<<i) != 0) continue;
        usedAddr += 1<<i;
        arr[missAddr[curAddr]] = missNum[i];
        backtrack(curAddr + 1);
        usedAddr -= 1<<i;
        arr[missAddr[curAddr]] = 0;
    }
}

int arrScore() {
    int score = 0;
    rep(i,0,N) {
        //printf("%d ", arr[i]);
        rep(j,i,N) if (arr[i] < arr[j]) score++;
    }
    //printf("  %d\n", score);
    return score;
}