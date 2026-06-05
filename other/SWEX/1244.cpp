#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);
void dfs(int depth);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

/*
    swap을 수행하는 dfs (자릿수-1)회 완탐으로 가장 큰 수 도출 가능
    if 어떤 수가 swap n회로 도출 가능할 경우 
    case 1 : 중복 수가 없을 경우 n+2, n+4회로도 도출 가능
    case 2 : 중복 수가 있을 경우 n이상인 모든 횟수로 도출 가능
    즉, swap 횟수가 (자릿수-1) 초과라면, 각 case 조건에 맞게 최대 swap 개수(=depth)를 조정
*/
char num[7];    // 원본 수를 string으로 변환한 것
int S;          // 최대 swap 횟수
int ans;        // 정답
int nlen;       // num의 자리수

void PS(int TCnum) {
    ans = 0;
    scanf("%s %d", num, &S);
    nlen = strlen(num); // 자릿수

    // 중복 체크용. 하나는 문자열 위치마다 or연산, 하나는 합연산
    int bor = 0;
    int bsum = 0;
    rep(i,0,nlen) {
        bor |= 1<<(num[i]-'0');
        bsum += 1<<(num[i]-'0');
    }
    
    int decS = 1;   // 위의 case 2일 때
    if (bor == bsum) decS = 2;  // case 1 조건일 시, S-1, S-3회일 때 나오는 값은 도출 불가능
    while (S > nlen) S -= decS; // 여기서의 S가 최종 depth
    dfs(0);
    printf("#%d %d\n", TCnum, ans);
}

void dfs(int depth) {
    if (depth == S) {
        if (ans < atoi(num)) ans = atoi(num);
        return;
    }

    rep(i,0,nlen) {
        rep(j,i+1,nlen) {
            char ln = num[i]; char rn = num[j];
            num[i] = rn; num[j] = ln;
            dfs(depth+1);
            num[i] = ln; num[j] = rn;
        }
    }
}