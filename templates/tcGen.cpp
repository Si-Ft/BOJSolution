#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    FILE *fp;
    fp = fopen("output.txt","w+");
    fprintf(fp, "50\n");

    //srand(time(NULL));
    rep(i,0,4000) {
        rep(i,0,4) {
            fprintf(fp, "0 ");
        }
        fprintf(fp, "\n");
    }

    return 0;
}