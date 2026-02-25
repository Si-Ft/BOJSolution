#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int numSeq[53] = {0}; // 원본 데이터
    int N, tot=0;
    scanf("%d", &N);

    for (int i=0;i<N;i++) {
        scanf("%d", numSeq+i);
    }

    int start=0, end=N-1; // 각각 합치지 않은 수의 주소값의 첫과 끝

    sort(numSeq, numSeq+N);

    // 음수값들 작은 순서대로 합치기 (0까지)
    while ((numSeq[start+1]<=0) && (start+1<N)) {
        tot += numSeq[start] * numSeq[start+1];
        start += 2;
    }
    // 양수값들 큰 순서대로 합치기 (2까지)
    while((numSeq[end-1]>=2) && (end-1>=0)) {
        tot += numSeq[end] * numSeq[end-1];
        end -= 2;
    }
    // 자투리 더하기
    for (;start<=end;start++) tot += numSeq[start];

    printf("%d", tot);

    return 0;
}