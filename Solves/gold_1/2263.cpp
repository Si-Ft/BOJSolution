#include <stdio.h>
#include <map>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int inorder[100001];
int postorder[100001];
map<int,int> inDict; // inorder 위치 탐색용

struct Node {
    int val = 0;
    Node *leftNode = NULL;
    Node *rightNode = NULL;
};

Node *makeTree(int Is, int Ie, int Ps, int Pe);
void treeTravel(Node *curNode);


int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) {
        scanf("%d", inorder+i);
        inDict.insert({inorder[i], i});
    }
    rep(i,0,N) scanf("%d", postorder+i);

    Node *rootNode = makeTree(0,N-1,0,N-1);
    treeTravel(rootNode);
    
    return 0;
}

Node *makeTree(int Is, int Ie, int Ps, int Pe){
    // Is~Ie, Ps~Pe 거리는 같으니 하나만 봄
    if (Is > Ie) return NULL;
    Node *curNode = new Node();
    curNode->val = postorder[Pe];
    if (Is == Ie) return curNode;

    int In = inDict.find(postorder[Pe])->second;
    int gap = In - Is;
    curNode->leftNode = makeTree(Is, Is+gap-1, Ps, Ps+gap-1);
    curNode->rightNode = makeTree(Is+gap+1, Ie, Ps+gap, Pe-1);
    return curNode;
}

void treeTravel(Node *curNode) {
    printf("%d ",curNode->val);
    if (curNode->leftNode) treeTravel(curNode->leftNode);
    if (curNode->rightNode) treeTravel(curNode->rightNode);
}