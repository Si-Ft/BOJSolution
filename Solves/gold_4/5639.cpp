#include <stdio.h>

struct Node {
    int val = 0;
    Node *leftNode = NULL;
    Node *rightNode = NULL;
};

void treeTravel(Node *searchNode);

int main() {
    Node *rootNode = NULL;
    int inp;
    int x;
    while (scanf("%d", &inp) == 1) {
        // 새 노드 생성
        Node *newNode = new Node();
        newNode->val = inp;
        if (rootNode == NULL) {
            rootNode = newNode;
            continue;
        }

        // 자기 자리 찾아서 붙이기
        Node *curNode = rootNode;
        while (curNode)
        {
            if (inp < curNode->val) { // 왼쪽 길로 가기
                if (curNode->leftNode == NULL) {
                    curNode->leftNode = newNode;
                    break;
                }
                curNode = curNode->leftNode;
            }
            else { // 오른쪽 길로 가기
                if (curNode->rightNode == NULL) {
                    curNode->rightNode = newNode;
                    break;
                }
                curNode = curNode->rightNode;
            }
        }
    }
    treeTravel(rootNode);

    return 0;
}

void treeTravel(Node *searchNode) {
    if (searchNode == NULL) return;
    treeTravel(searchNode->leftNode);
    treeTravel(searchNode->rightNode);
    printf("%d\n", searchNode->val);
}