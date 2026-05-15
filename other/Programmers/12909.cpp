// 코딩테스트 연습 >> 스택/큐 >> 올바른 괄호

#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int cnt = 0;
    for (char c : s) {
        if (c == '(') {
            cnt++;
        } else {
            cnt--;
            if (cnt < 0) {
                return false;
            }
        }
    }

    return cnt == 0;
}