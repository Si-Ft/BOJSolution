#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    FILE *fp;
    fp = fopen("output.txt","w+");
    fprintf(fp, "2000\n");

    srand(time(NULL));
    rep(i,0,2000) {
        int x1 = ((rand()%9)-4) * i + (rand()%32);
        int x2 = ((rand()%9)-4) * i + (rand()%32);
        int x3 = ((rand()%9)-4) * i + (rand()%32);
        int x4 = ((rand()%9)-4) * i + (rand()%32);
        fprintf(fp, "%d %d %d %d\n", x1, x2, x3, x4);
    }

    return 0;
}