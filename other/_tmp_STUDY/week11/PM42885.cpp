#include <string>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

/*
  정렬해서 맨 앞 맨 뒤 사람을 보는 방법으로 푸는 건 알고 있긴 하지만
  이상한 방법으로 풀어보고 싶었습니다
*/
int solution(vector<int> people, int limit) {
    int answer = 0;
    int weights[241] = {0};
    for (int weight: people) weights[weight]++;

    // 최대 용량
    rrep(i,limit,1) {
      // 딱 맞는 사람 태우기
      answer += weights[i];
      weights[i] = 0;

      // 2명 태우기
      rep(j,0,limit) {
        if (j > i-j) break; // 중복 검사 방지
        int board = min(weights[j], weights[i-j]);

        if (i-j == j) board /= 2;
        answer += board;
        weights[j] -= board;
        weights[i-j] -= board;
      }

    }
    return answer;
}