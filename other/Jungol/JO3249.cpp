#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int N;
char seq[2000001];
int seqidx = 0;
int grid[1024][1024];

void recursion(int y, int x, int size);
void fillGrid(int y, int x, int size, int fn);

int main() {
    scanf("%d", &N);
    scanf("%s", seq);

    recursion(0,0,N);

    printf("%d\n", N);
    rep(i,0,N) {
        rep(j,0,N) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

// 가로좌표, 세로좌표, 정사각형 크기, seq char배열의 위치
void recursion(int y, int x, int size) {
    char s = seq[seqidx++];
    if (s != 'X') {
        // 이 함수의 값을 이용해 전부 s의 숫자로 채움
        int fn = s - '0';
        fillGrid(y,x,size,fn);
        return;
    }

    recursion(y,x,size/2);  // 좌상
    recursion(y,x+size/2,size/2);   // 우상
    recursion(y+size/2,x,size/2);   // 좌하
    recursion(y+size/2,x+size/2,size/2);    // 우하
}

void fillGrid(int y, int x, int size, int fn) {
    rep(i,y,y+size) {
        rep(j,x,x+size) {
            grid[i][j] = fn;
        }
    }
}