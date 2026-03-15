#include <stdio.h>
#include <deque>
using namespace std;

char p[100001];
int N;
deque<int> arr;
int main() {
    int T;
    scanf("%d", &T);
    for (int tc=0;tc<T;tc++) {
        scanf("%s", p);
        scanf("%d", &N);

        char tmp;
        int num = 0;
        
        while(1) {
            scanf("%c", &tmp);
            if (tmp < '0' || tmp > '9') {
                if (num != 0) arr.push_back(num);
                num = 0;
                if (tmp == ']') break;
                continue;
            }
            num *= 10;
            num += tmp-'0';
        }

        bool isError = false;
        bool direction = false;
        for (int i=0;p[i]!='\0';i++) {
            if (p[i] == 'R') {
                direction = !direction;
                continue;
            }
            if (arr.size() <= 0) {
                printf("error\n");
                isError = true;
                break;
            }
            if (direction) arr.pop_back();
            else arr.pop_front();
        }

        if (isError) continue;

        printf("[");
        while(arr.size() > 0) {
            if (direction) {
                printf("%d",arr.back());
                arr.pop_back();
            }
            else {
                printf("%d",arr.front());
                arr.pop_front();
            }
            if (arr.size()) printf(",");
            else break;
        }
        printf("]\n");
    }
    return 0;
}