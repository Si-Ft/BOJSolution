#include <stdio.h>

char star[7000];
int N;

void jwaegi (int step);

int main() {
    scanf("%d", &N);
    for (int i=0;i<N*2;i++) star[i] = ' ';
    star[N*2-1] = '\n';
    star[N-1] = '*';

    printf("%s", star);
    for (int i=1;i<N;i++) jwaegi(i);

    return 0;
}

void jwaegi (int step) {
    for (int i=0;i<N*2-1;i++) {
        //printf("%d", i);
        if (star[i] == ' ') continue;

        if (step % 3 == 1) {
            star[i-1] = '*';
            star[i] = ' ';
            star[i+1] = '*';
            i++;
        }

        if (step % 3 == 2) {
            star[i-1] = '*';
            star[i+1] = '*';
            i++;
        }

        if (step % 3 == 0) {
            if (star[i-2] == ' ') star[i-1] = '*'; 
            if (star[i+6] == ' ') star[i+5] = '*'; 
            for (int j=0;j<5;j++) star[i+j] = '-';
            i+=5;
        }
    }

    for (int i=0;i<N*2-1;i++) if (star[i]=='-') star[i]=' ';
    printf("%s", star);
}