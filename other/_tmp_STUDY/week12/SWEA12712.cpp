#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N,M;
        int grid[16][16];
        scanf("%d %d", &N, &M);
        M--;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
            	scanf("%d", &grid[i][j]);
        	}
        }
        int mx=0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
            	// 세로방향 (x축고정)
                int cmx=0;
                for (int y=i-M;y<=i+M;y++) {
                    if (y<0 || y>=N) continue;
                    cmx += grid[y][j];
                }
                // 가로방향 (y축고정)
                for (int x=j-M;x<=j+M;x++) {
                    if(x<0 || x>=N) continue;
                    cmx += grid[i][x];
                }
                cmx -= grid[i][j];
                
                mx = max(cmx, mx);
                cmx=0;
                
                // 좌상->우하 방향
                for(int t=-M; t<=M; t++) {
                    if (i+t<0 || i+t>=N || j+t<0 || j+t>=N) continue;
                    cmx += grid[i+t][j+t];
                }
                // 좌하->우상 방향
                for(int t=-M; t<=M; t++) {
                    if (i-t<0 || i-t>=N || j+t<0 || j+t>=N) continue;
                    cmx += grid[i-t][j+t];
                }
                cmx -= grid[i][j];
                
                mx = max(cmx, mx);
                
        	}
        }
        
        printf("#%d %d\n",test_case, mx);
	}
	return 0;
}