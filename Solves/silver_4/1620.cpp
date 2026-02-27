#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int,string> findByNum;
    map<string,int> findByName;

    int N,M;
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++) {
        char name[25];
        scanf("%s", name);
        findByNum.insert({i+1,name});
        findByName.insert({name,i+1});
    }

    for (int i=0;i<M;i++) {
        char inp[25];
        scanf("%s", inp);
        if (inp[0] < 60) {
            int pnum = stoi(inp);
            printf("%s\n", findByNum.find(pnum)->second.c_str());
        }
        else printf("%d\n", findByName.find(inp)->second);
    }

    return 0;
}