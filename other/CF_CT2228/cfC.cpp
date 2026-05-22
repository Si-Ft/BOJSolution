#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

void PS(int TCnum);
int digits(long long x);
long long minNum(int aDigits, const vector<int>& usedN);
long long maxNum(int aDigits, const vector<int>& usedN);
void dfs(int depth, long long curNum);

long long pow10[19];

int main() {
    for(int i=0; i<19; i++) {
        if (i == 0) pow10[i] = 1;
        else pow10[i] = pow10[i-1]*10;
    }

    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    return 0;
}

long long a;
long long ans;
int n;
vector<int> usedN;

void PS(int TCnum) {
    scanf("%lld %d", &a, &n);
    usedN.clear();
    rep(i,0,n) {
        int x;
        scanf("%d", &x);
        usedN.push_back(x);
    }

    // 극값 체크
    if (n == 1 && usedN[0] == 0) {
        printf("%lld\n", a);
        return;
    }

    if (a == 0) {
        printf("%lld\n", abs(a - usedN[0]));
        return;
    }

    int aDigits = digits(a); // a의 자릿수
    long long biggerNum = -1, smallerNum = -1;
    if (aDigits <= 17) {
        biggerNum = minNum(aDigits+1, usedN);
    }
    if (aDigits >= 2) {
        smallerNum = maxNum(aDigits-1, usedN);
    }
    ans = abs(biggerNum - a);
    ans = min(ans, a - smallerNum);

    //printf("%lld, %lld\n", biggerNum, smallerNum);
    int curDigit = a / pow10[aDigits-1] % 10;
    int nearSame = -1, nearMin = -1, nearMax = -1;
    rep(i,0,n) { // 같은수, 가장 가까운 작은 자리수 찾기
        if (usedN[i] < curDigit) nearMin = usedN[i];
        else if (usedN[i] == curDigit) nearSame = usedN[i];
    }
    rrep(i,n-1,0) { // 가장 가까운 큰 자리수 찾기
        if (usedN[i] > curDigit) nearMax = usedN[i];
    }

    if (nearSame != -1) dfs(aDigits-1, (long long)nearSame*pow10[aDigits-1]);
    if (nearMin > 0) dfs(aDigits-1, (long long)nearMin*pow10[aDigits-1]);
    if (nearMax != -1) dfs(aDigits-1, (long long)nearMax*pow10[aDigits-1]);

    printf("%lld\n", ans);
}

int digits(long long x) {
    int cnt = 0;
    while(x > 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

// usedN의 숫자만을 사용해서 aDigits 자리의 수 중 가장 작은 수를 구하는 함수
long long minNum(int aDigits, const vector<int>& usedN) {
    long long ret = 0;
    if (usedN[0] == 0) ret = usedN[1];
    else ret = usedN[0];
    rep(i,1,aDigits) {
        ret *= 10;
        ret += usedN[0];
    }
    return ret;
}

long long maxNum(int aDigits, const vector<int>& usedN) {
    long long ret = 0;
    ret = usedN[n-1];
    rep(i,1,aDigits) {
        ret *= 10;
        ret += usedN[n-1];
    }
    return ret;
}


// depth : digit위치, curNum : 현재까지 만들어진 수
// curNum의 첫 값은 미리 계산
void dfs(int depth, long long curNum) {
    if (depth <= 0) {
        ans = min(ans, abs(a - curNum));
        return;
    }
    int curDigit = a / pow10[depth-1] % 10;

    if (a / pow10[depth] == curNum / pow10[depth]) {
        int nearSame = -1, nearMin = -1, nearMax = -1;
        rep(i,0,n) { // 같은수, 가장 가까운 작은 자리수 찾기
            if (usedN[i] < curDigit) nearMin = usedN[i];
            else if (usedN[i] == curDigit) nearSame = usedN[i];
        }
        rrep(i,n-1,0) { // 가장 가까운 큰 자리수 찾기
            if (usedN[i] > curDigit) nearMax = usedN[i];
        }
        if (nearSame != -1) dfs(depth-1, curNum + (long long)nearSame*pow10[depth-1]);
        if (nearMin != -1) dfs(depth-1, curNum + (long long)nearMin*pow10[depth-1]);
        if (nearMax != -1) dfs(depth-1, curNum + (long long)nearMax*pow10[depth-1]);
    }
    else if (a / pow10[depth] > curNum / pow10[depth]) {
        // 가장 큰 수로 채우기
        curNum += usedN[n-1] * pow10[depth-1];
        dfs(depth-1, curNum);
        return;
    }
    else {
        // 가장 작은 수로 채우기
        curNum += usedN[0] * pow10[depth-1];
        dfs(depth-1, curNum);
        return;
    }
}