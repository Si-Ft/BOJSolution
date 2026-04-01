#include <stdio.h>
#include <string.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

char gongyak[7][52] = { "Never gonna give you up\n\0", "Never gonna let you down\n\0", 
"Never gonna run around and desert you\n\0", "Never gonna make you cry\n\0",
"Never gonna say goodbye\n\0" , "Never gonna tell a lie and hurt you\n\0" ,
"Never gonna stop\n\0"};

int main() {
    int N;
    scanf("%d ", &N);

    bool isRAgongyak = false;
    rep(i,0,N) {
        char inp[52];
        fgets(inp, sizeof(inp), stdin);
        bool isSame = false;
        rep(j,0,7) if (strcmp(inp, gongyak[j]) == 0) isSame = true;
        if (!isSame) isRAgongyak = true;
    }

    if (isRAgongyak) printf("Yes");
    else printf("No");
    return 0;
}