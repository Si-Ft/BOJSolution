#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int myUnion[50001] = {0};
int unionCount[50001] = {0};

void setunion(int A, int B);
int findunion(int A);

int main() {
    int N,Q;
    scanf("%d %d", &N, &Q);

    rep(i,1,N+1) {
        myUnion[i] = i;
        unionCount[i] = 1;
    }

    rep(i, 0, Q) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            setunion(x, y);
        }
        else {
            int x;
            scanf("%d", &x);
            printf("%d\n", unionCount[findunion(x)]);
        }
    }
    
    return 0;
}

void setunion(int A, int B) {
    int uA = findunion(A);
    int uB = findunion(B);
    if (uA != uB) {
        myUnion[uB] = uA;
        unionCount[uA] += unionCount[uB];
    }
}

int findunion(int A) {
    if (myUnion[A] == A) {
        return A;
    }
    else {
        return myUnion[A] = findunion(myUnion[A]);
    }
}