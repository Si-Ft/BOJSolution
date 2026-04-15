#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int charToBit(char inp[9]) {
    int ret = 0;
    rep(i,0,8) if (inp[i] == '1') ret |= (1 << (7 - i));
    return ret;
}

void bitToChar(int num, char out[9]) {
    rep(i,0,8) {
        // 비트마스크 사용, 비트가 있다면 1, 없다면 0
        out[i] = (num & (1 << (7 - i))) ? '1' : '0';
    }
    out[8] = '\0';
    return;
}

int PS() {
    char inp[9]; // 입력
    int mem[32] = {0}; // 메모리
    int adder = 0; // 가산기

    if (scanf("%s", inp) == EOF) return 0;
    mem[0] = charToBit(inp);
    rep(i,1,32) {
        scanf("%s", inp);
        mem[i] = charToBit(inp);
    }

    rep(pc,0,33) {
        if (pc>=32) pc-=32;
        int cmd = mem[pc] >> 5;
        int val = mem[pc] % 32;

        //printf("Line %d >> cmd:%d, val:%d, adder:%d\n",pc,cmd,val,adder);

        switch (cmd)
        {
        case 0:
            mem[val] = adder;
            break;
        case 1:
            adder = mem[val];
            break;
        case 2:
            if (adder == 0) pc = val-1; 
            break;
        case 4:
            adder--;
            break;
        case 5:
            adder++;
            break;
        case 6:
            pc = val-1; 
            break;
        case 7:
            char out[9];
            bitToChar(adder, out);
            printf("%s\n", out);
            return 1;
        }
        adder = (adder + 256) % 256;
    }

    return 1;
}

int main() {
    while (PS());
    
    return 0;
}