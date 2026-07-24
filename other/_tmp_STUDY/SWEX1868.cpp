#include <stdio.h>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
 
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
void PS(int TCnum);
 
int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
     
    return 0;
}
 
void PS(int TCnum) {
    int N;
    char grid[300][300];
    bool visited[300][300] = {false};
    int nums = 0;   // 주변에 지뢰가있는 숫자 수
     
    scanf("%d", &N);
    rep(i,0,N) scanf("%s", grid[i]);
     
    rep(i,0,N) {
        rep(j,0,N) {
            if (grid[i][j] == '*') {
                rep(k,0,8) {
                    int ny = i+dy[k];
                    int nx = j+dx[k];
                    if (ny<0 || ny>=N || nx<0 || nx>=N) continue;
                    if (grid[ny][nx] == '.') {
                        grid[ny][nx] = '0';
                        nums++;
                    }
                }
            }
        }
    }
    // rep(i,0,N) printf("%s\n", grid[i]);
     
    // . 위치에 있는 곳을 기준으로 bfs
    int ans = 0;
    rep(i,0,N) {
        rep(j,0,N) {
            if (grid[i][j] != '.' || visited[i][j] == true) continue;
            ans++;
            queue<int> q;
            q.push(i*1000+j);
            visited[i][j] = true;
            while(!q.empty()) {
                int cy = q.front() / 1000;
                int cx = q.front() % 1000;
                q.pop();
                rep(k,0,8) {
                    int ny = cy + dy[k];
                    int nx = cx + dx[k];
                    if (ny<0 || ny>=N || nx<0 || nx>=N) continue;
                    if (visited[ny][nx]) continue;
                     
                    visited[ny][nx] = true;
                    if (grid[ny][nx] == '0') {
                        nums--;
                        continue;
                    }
                    q.push(ny*1000+nx);
                }
            }
        }
    }
     
    printf("#%d %d\n", TCnum, ans+nums);
     
     
}