// P5
#include <stdio.h>
#include <algorithm>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int A[51];
// A[i] = (값, 개수)
vector<pair<int, int>> indepA;

void arraySwap(int begin, int end);

int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) scanf("%d", &A[i]);
    sort(A, A+N);

    rep(i,0,N) {
        if (i == 0 || A[i] != A[i-1]) {
            int count = 1;
            while (i+1 < N && A[i+1] == A[i]) {
                count++;
                i++;
            }
            indepA.push_back({A[i], count});
        }
    }

    // 연속된 수
    int start=0, end=0;
    while(end<indepA.size()-1) {
        if ((indepA[++end-1].first + 1) < indepA[end].first) continue;
        start = end-1;
        while (end < N && (indepA[end-1].first + 1) == indepA[end].first) {
            end++;
        }
        arraySwap(start, end-1);
    }

    // indepA first에 있는 값을 second개수만큼 출력
    for (const auto& p : indepA) {
        for (int i = 0; i < p.second; i++) {
            printf("%d ", p.first);
        }
    }

    return 0;
}

// 연속된 수들일 경우, 연속되지 않게 바꾸기
void arraySwap(int begin, int end) {
    int size = end-begin+1;
    if (size%3 == 1) end--;
    else if (size%3 == 2) {
        swap(indepA[end], indepA[end-1]);
        end -= 2;
    }
    // 여기서 end는 3의 배수
    for (int i=begin; i<end; i+=3) {
        swap(indepA[i+1], indepA[i+2]);
    }
}
