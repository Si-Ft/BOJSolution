#include <string>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int Ysize, Xsize;
char mp[100][100];
int bfs(int sy, int sx, char endp);

int solution(vector<string> maps) {
  // 맵 정보를 mp에 저장하고, S,L의 좌표를 미리 저장
  Ysize = maps.size();
  Xsize = maps[0].size();

  int y=0, x=0, sy, sx, ly, lx;
  for (string row : maps) {
    for (char c : row) {
      mp[y][x++] = c;
      if (c == 'S') { sy=y; sx=x-1; }
      if (c == 'L') { ly=y; lx=x-1; }
    }
    y++;
    x=0;
  }
  // 시작점 -> 레버로 가는 최단거리
  int l1 = bfs(sy,sx,'L');
  if (l1 == -1) return -1;

  // 레버 -> 출구로 가는 최단거리
  int l2 = bfs(ly,lx,'E');
  if (l2 == -1) return -1;
  return l1+l2;
}

int dist[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int bfs(int sy, int sx, char endp) {
  rep(i,0,Ysize) rep(j,0,Xsize) dist[i][j] = -1;
  queue<pair<int,int>> q;
  q.push({sy,sx});
  dist[sy][sx] = 0;

  while (!q.empty()) {
    auto [y,x] = q.front(); q.pop();
    if (mp[y][x] == endp) return dist[y][x];

    rep(i,0,4) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny<0 || ny>=Ysize || nx<0 || nx>=Xsize) continue;
      if (mp[ny][nx] == 'X') continue;
      if (dist[ny][nx] != -1) continue;

      dist[ny][nx] = dist[y][x] + 1;
      q.push({ny,nx});
    }
  }
  
  return -1;
}