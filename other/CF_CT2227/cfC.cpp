#include <stdio.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    vector<int> div6;
    vector<int> div3;
    vector<int> div2;
    vector<int> lefts;

    int N;
    scanf("%d", &N);

    rep(i,0,N) {
        int a;
        scanf("%d", &a);
        if (a % 6 == 0) div6.push_back(a);
        else if (a % 3 == 0) div3.push_back(a);
        else if (a % 2 == 0) div2.push_back(a);
        else lefts.push_back(a);
    }

    for (int i : div6) printf("%d ", i);
    if (div3.size() < div2.size()) {
        for (int i : div3) printf("%d ", i);
        for (int i : lefts) printf("%d ", i);
        for (int i : div2) printf("%d ", i);
    }
    else {
        for (int i : div2) printf("%d ", i);
        for (int i : lefts) printf("%d ", i);
        for (int i : div3) printf("%d ", i);
    }
    printf("\n");
}