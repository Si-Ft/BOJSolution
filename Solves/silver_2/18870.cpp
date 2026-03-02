#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int N;
int originNum[1000001];
int sortNum[1000001];
map<int,int> axis;

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        scanf("%d", originNum+i);
        sortNum[i] = originNum[i];
    }

    sort(sortNum, sortNum+N);

    int curNum = -__INT_MAX__;
    int convertNum = 0;
    for (int i=0;i<N;i++) {
        if (curNum == sortNum[i]) continue;
        curNum = sortNum[i];
        axis.insert({curNum, convertNum});
        convertNum++;
    }

    for (int i=0;i<N;i++) printf("%d ", axis.find(originNum[i])->second);
    return 0;
}