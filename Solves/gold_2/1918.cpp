#include <stdio.h>
#include <stack>
using namespace std;

// 부호 우선순위 비교 ( +,-,*,/,(,) )
int compCal(char C1, char C2) {
    if (C1 == '+' || C1 == '-') C1 = 1;
    else if (C1 == '*' || C1 == '/') C1 = 2;
    else C1 = 3;

    if (C2 == '+' || C2 == '-') C2 = 1;
    else if (C2 == '*' || C2 == '/') C2 = 2;
    else C2 = 3;

    // 앞에것이 크면 -1, 뒤에것이 크면 1, 같으면 0
    if (C1<C2) return 1;
    else if (C1>C2) return -1;
    else return 0;
}

int main() {
    char oStr[101];
    stack<char> storeCal;
    scanf("%s", oStr);

    for (int i=0;oStr[i];i++) {
        // 알파벳일 경우 그냥 출력
        if (oStr[i]>60) {
            printf("%c",oStr[i]);
            continue;
        }

        if (storeCal.empty()) {
            storeCal.push(oStr[i]);
            continue;
        }

        if (oStr[i] == ')') {
            while (storeCal.top() != '(') {
                printf("%c",storeCal.top());
                storeCal.pop();
            }
            storeCal.pop();
            continue;
        }

        while(compCal(storeCal.top(), oStr[i]) <= 0) {
            if (storeCal.top() == '(') break;
            printf("%c",storeCal.top());
            storeCal.pop();
            if (storeCal.empty()) break;
        }
        storeCal.push(oStr[i]);
    }

    while (!storeCal.empty()) {
        printf("%c",storeCal.top());
        storeCal.pop();
    }

    return 0;
}