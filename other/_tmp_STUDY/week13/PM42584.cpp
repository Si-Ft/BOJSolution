#include <string>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<pair<int,int>> st;       // 값, index

    rep(i,0,prices.size()) {
        while(!st.empty()) {
            if (st.back().first > prices[i]) {
                answer[st.back().second] = i - st.back().second;
                st.pop_back();
            } else {
                break;
            }
        }
        st.emplace_back(prices[i], i);
    }

    while(!st.empty()) {
        answer[st.back().second] = prices.size() - st.back().second - 1;
        st.pop_back();
    }
    
    return answer;
}