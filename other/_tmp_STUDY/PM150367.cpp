#include <string>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int findMaxNum(long long n);
int treeTraversal(int treeNum, int maxNum);

long long N;
int bitPos; // treeTraversal 중 확인할 비트의 위치
vector<int> solution(vector<long long> numbers) {
    vector<int> ans;

    // 각 num의 원소를 전역변수 N에 대입
    for (long long tN : numbers) {
        N = tN;
        int mN = findMaxNum(N);

        // 이진트리 size가 3인 경우 N & 1<<(3-1) 위치의 비트부터 봐야함
        bitPos = mN - 1;
        // 불가능한게 아니라면 1 리턴, 불가능하다면 0 리턴한 걸 바로 값에 넣음.
        ans.push_back(treeTraversal(1,mN)>0?1:0);
    }

    return ans;
}

// 각 숫자에 대해서 treeTraversal에서 사용할 "포화 이진 트리"의 "노드 개수"를 리턴함.
int findMaxNum(long long n) {
    int ret = 1;
    n = n>>1;
    int m = 2;
    while(n>0) {
        n = n>>m;
        ret += m;
        m*=2;
    }
    return ret;
}

// 가상의 tree를 순회하는 함수
// tree의 최대 node 수 : 1, 3, 7, ... , 63
// 가능한 경우 : 0,1 | 불가능한 경우 : -1
int treeTraversal(int treeNum, int maxNum) {
    // leaf 노드인 경우
    if (treeNum*2 > maxNum) {
        if (N & 1LL<<bitPos--) return 1;
        else return 0;
    }

    int ret1 = treeTraversal(treeNum*2, maxNum);
    int ret2 = N & 1LL<<bitPos-- ? 1 : 0;
    int ret3 = treeTraversal(treeNum*2+1, maxNum);

    // 하나라도 불가능하면 -1 리턴
    if (ret1 == -1 || ret3 == -1) return -1;
    // 세 ret값이 전부 0이거나, ret2값이 1이라면 해당 값 리턴
    if (ret1 + ret2 + ret3 == 0) return 0;
    else if (ret2) return 1;
    // 두 경우 아니라면 (leaf노드중 하나가 1인데 루트가 0인 경우) -1 리턴
    return -1;
}