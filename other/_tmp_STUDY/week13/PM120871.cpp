#include <string>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int solution(int n) {
    int answer = 0;

    int targetn = 0;
    while(targetn < n) {
        answer++;
        if (answer%3 == 0 || answer%10 == 3 || (answer/10)%10 == 3) continue;
        targetn++;
    }

    return answer;
}