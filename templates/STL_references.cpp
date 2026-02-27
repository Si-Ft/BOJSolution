#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

int main() {
    // Vector 사용법 (헤더 : <vector>)
    // 2차원 배열 선언 예시, 1차원단의 배열 10개
    vector<vector<pair<int,int>>> vectorName(10);

    // 2차원 배열에 넣기
    vectorName[1].emplace_back(2,3);
    vectorName[0].emplace_back(4,5);


    // Map 사용법 (헤더 : <map>)
    // 선언 : map<type, type>
    map<int, int> mapName;

    // map에 데이터 넣고 제거하기
    mapName.insert({123,456});
    mapName.insert({11,22});
    mapName.erase(11);

    // map에서 데이터 찾기
    int iter = mapName.find(123)->second;
    auto iter2 = mapName.find(69);
    if (iter2 == mapName.end()) printf("Not Found");

    return 0;
}