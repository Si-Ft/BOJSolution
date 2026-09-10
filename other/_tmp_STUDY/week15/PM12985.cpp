#include <iostream>

using namespace std;
int solution(int n, int a, int b)
{
    a--; 
    b--;
    int answer = 0;

    // a,b를 비트마스크로 치환해서 같은 비트가 나옴 = 같은 라운드에서 만남
    while (a != b) {
        a >>= 1;
        b >>= 1;
        answer++;
    }
    return answer;
}