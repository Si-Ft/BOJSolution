#include <stdio.h>
#include <string.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void printHr();
void printBuff(char buff[], int len);

int main() {
    char inp[81];
    char buff[81];
    int buffptr = 0;
    while (scanf("%s", inp) != EOF) {
        if (inp[0] == '<') {
            if (inp[1] == 'b') {
                printBuff(buff, buffptr);
                buffptr = 0;
            }
            else if (inp[1] == 'h') {
                if (buffptr != 0) {
                    printBuff(buff, buffptr);
                    buffptr = 0;
                }
                printHr();
            }
            continue;
        }

        int inplen = strlen(inp);
        if (buffptr + inplen + (buffptr > 0) > 80) {
            printBuff(buff, buffptr);
            buffptr = 0;
        }

        if (buffptr > 0) buff[buffptr++] = ' ';
        rep(i, 0, inplen) buff[buffptr++] = inp[i];

    }
    if (buffptr > 0) printBuff(buff, buffptr);
    return 0;
}

void printHr() {
    rep(i, 0, 8) printf("----------");
    printf("\n");
}

void printBuff(char buff[], int len) {
    rep(i, 0, len) printf("%c", buff[i]);
    printf("\n");
}