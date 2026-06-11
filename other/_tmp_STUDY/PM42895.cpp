#include <string>
#include <vector>
#include <set>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

// 각 사용한 숫자의 개수에 따라 가능한 정답들
vector<set<int>> possibleNums(9);
int solution(int N, int number) {
    int answer = -1;

    // 미리 중복해서 붙인 수를 준비해둠
    int sameNum = 0;
    rep(i,1,9) {
        sameNum = sameNum*10 + N;
        possibleNums[i].insert(sameNum);
        // 중복해서 붙인 수가 대상 수라면, 바로 리턴 (최소 개수 사용임이 보장)
        if (sameNum == number) return i;
    }

    // i == depth, 8개의 수를 쓸 때까지 반복
    rep(i,2,9) {
        /*
            각 숫자집합의 괄호 -
            (사용수 1개) (연산자) (사용수 depth-1개)
            (사용수 2개) (연산자) (사용수 depth-2개)
            ...
            (사용수 depth-1개) (연산자) (사용수 1개)
        */
        // k == 사용 수
        rep(k,1,i) {
            for (int n1 : possibleNums[k]) {
                for (int n2 : possibleNums[i-k]) {
                    //printf("n1: %d, n2: %d\n", n1, n2);

                    possibleNums[i].insert(n1 - n2);
                    if (n1 - n2 == number) return i;
                    if (n2 != 0) {
                        possibleNums[i].insert(n1 / n2);
                        if (n1 / n2 == number) return i;
                    }

                    if (k > i-k) continue;

                    possibleNums[i].insert(n1 + n2);
                    if (n1 + n2 == number) return i;
                    possibleNums[i].insert(n1 * n2);
                    if (n1 * n2 == number) return i;
                }
            }
        }
    }
    return answer;
}

int main() {
    int N = 2;
    int number = 2147483647;
    printf("%d\n", solution(N, number));
    return 0;
}