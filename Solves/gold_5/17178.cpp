#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<pair<int,int>> tickets;
vector<pair<int,int>> sortedTickets;
stack<pair<int,int>> waitline;

int comp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second > b.second;

}

int main() {
    int N;
    scanf("%d", &N);
    N *= 5;
    rep(i,0,N) {
        char ticketNum[7];
        scanf("%s", ticketNum);
        int letter = (int)ticketNum[0];
        int number = atoi(&ticketNum[2]);
        tickets.push_back(make_pair(letter, number));
        sortedTickets.push_back(make_pair(letter, number));
    }
    // 맨 마지막 티켓이 가장 먼저 나가야 하므로, 편의 상 내림차순으로 정렬
    sort(sortedTickets.begin(), sortedTickets.end(), comp);

    int curEntry = 0;
    while (!sortedTickets.empty()) {
        pair<int,int> curTicket = tickets[curEntry];
        if (curTicket == sortedTickets.back()) {
            sortedTickets.pop_back();
            curEntry++;
        }
        else if (!waitline.empty() && waitline.top() == sortedTickets.back()) {
            waitline.pop();
            sortedTickets.pop_back();
        }
        else if (curEntry < tickets.size()) {
            waitline.push(curTicket);
            curEntry++;
        }
        else {
            printf("BAD");
            return 0;
        }
    }
    printf("GOOD");
    return 0;
}