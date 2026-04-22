#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    FILE *fp;
    fp = fopen("output.txt","w+");
    fprintf(fp, "50\n");

    srand(time(NULL));
    rep(i,0,50) {
        rep(i,0,50) {
            fprintf(fp, "%d ", rand()%10);
        }
        fprintf(fp, "\n");
    }

    return 0;
}