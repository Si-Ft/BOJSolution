#include <stdio.h>
#include <vector>
using namespace std;

vector<char> preTravel; // 전위 순회
vector<char> inTravel; // 중위 순회
vector<char> postTravel; // 후위 순회

int tree[30][2] = {0};

void treeTravel(int curNode);

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0;i<N;i++) {
        char inp[3];
        scanf(" %c %c %c", inp, inp+1, inp+2);
        if (inp[1] != 46) tree[inp[0]-64][0] = inp[1]-64;
        if (inp[2] != 46) tree[inp[0]-64][1] = inp[2]-64;
    }

    // A : 65, . : 46 || A는 address상 1부터 시작
    treeTravel(1); // A부터 순회

    for (char next : preTravel) printf("%c", next);
    printf("\n");
    for (char next : inTravel) printf("%c", next);
    printf("\n");
    for (char next : postTravel) printf("%c", next);

    return 0;
}

void treeTravel(int curNode) {
    // 초기 curNode는 루트
    preTravel.push_back(curNode+64);

    // 왼쪽 자식 순회
    if (tree[curNode][0]) treeTravel(tree[curNode][0]);
    inTravel.push_back(curNode+64);

    // 오른쪽 자식 순회
    if (tree[curNode][1]) treeTravel(tree[curNode][1]);
    postTravel.push_back(curNode+64);
}