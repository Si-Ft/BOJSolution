#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int spots[3001] = {0};
int myUnion[10001] = {0};
vector<pair<int,int>> nearSpots; // 가까운 지점들, pair<거리, 지점번호>

// idx : 시작점, 0:끝점, 1:총 비용, 2:개수
int headCost[10001][3] = {0};

void setunion(int A, int B);
int findunion(int A);

int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) {
        scanf("%d", &spots[i]);
        myUnion[spots[i]] = spots[i];
        headCost[spots[i]][0] = spots[i];
        headCost[spots[i]][2] = 1;
    }

    sort(spots, spots+N);
    int T, H; // 트럭을 쓸 때, 헬리콥터를 쓸 때 비용
    int useHeli = 0; // 헬리콥터가 이득이 되는 순간
    scanf("%d %d", &T, &H);
    rep(i,0,N) {
        int truckCost = spots[i] * T;
        if (truckCost <= H) {
            headCost[spots[i]][1] = truckCost;
            useHeli = i+1;
        }
        else headCost[spots[i]][1] = H;
    }

    rep(i,useHeli,N-1) {
        nearSpots.push_back({i, i+1});
    }

    // 지점의 index 간 거리가 가까운 순으로 정렬
    sort(nearSpots.begin(), nearSpots.end(), [](pair<int,int> a, pair<int,int> b) {
        return spots[a.second] - spots[a.first] < spots[b.second] - spots[b.first];
    });

    for (auto nearSpot : nearSpots) {
        int leftSpot = spots[nearSpot.first];
        int rightSpot = spots[nearSpot.second];
        leftSpot = findunion(leftSpot);
        rightSpot = findunion(rightSpot);

        int lesscount = min(headCost[leftSpot][2], headCost[rightSpot][2]);
        // if ( (적은 쪽의 개수 * 두 지점 거리) < 헬리콥터비용 ) 이라면, 합치는 게 이득이다.
        if (lesscount * (rightSpot - leftSpot) * T < H) {
            setunion(leftSpot, rightSpot);
            int newSpot = findunion(leftSpot);
            headCost[newSpot][0] = leftSpot;
        }
    }

    int answer = 0;
    rep(i,0,N) {
        int spot = findunion(spots[i]);
        answer += headCost[spot][1];
    }
    printf("%d", answer);

}

void setunion(int A, int B) {
    int uA = findunion(A);
    int uB = findunion(B);
    if (uA != uB) {
        myUnion[uB] = uA;
        // headCost[uA] += headCost[uB];
    }
}

int findunion(int A) {
    if (myUnion[A] == A) {
        return A;
    }
    else {
        return myUnion[A] = findunion(myUnion[A]);
    }
}