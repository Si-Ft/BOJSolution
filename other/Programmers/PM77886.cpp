#include <string>
#include <vector>
#include <iostream>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

string eachans(string s);

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (string cs : s) {
        if (cs.length() > 3) cs = eachans(cs);
        answer.push_back(cs);
    }

    return answer;
}

string eachans(string s) {
    // 110 꺼내기
    vector<char> st;
    int c110s = 0;
    for (char c : s) {
        st.push_back(c);
        if (st.size() < 3) continue;
        if (st[st.size()-3] == '1' &&
            st[st.size()-2] == '1' &&
            st[st.size()-1] == '0') {
            c110s++;
            rep(i,0,3) st.pop_back();
        }
    }
    /*
    뒤에서부터 0을 찾음
    이게 가능한 이유는 0을 찾았을 때, 00, 10 같은 수들은 애초에 먼저오는게 맞고
    1...10같은 수는 이미 110이 만들어져서 빠지기 때문에 고려 대상이 아님
    이걸 생각 못해서 한참 헤맴
    */ 
    int iidx;  // 110 뭉탱이를 끼워넣을 인덱스 값
    for (iidx=st.size()-1; iidx>=0; iidx--) {
        if (st[iidx] == '0') break;
    }
    iidx++;

    string ret;
    rep(i,0,st.size()+1) {
        if (iidx == i) {
            while(c110s) {
                ret.append("110");
                c110s--;
            }
        }

        if (i == st.size()) break;
        ret.push_back(st[i]);
    }

    return ret;
}

/*
string eachans(string s) {
    int c110s = 0;  // s의 역순으로 보면서 감지된 110의 개수
    vector<char> leftover;  // 110을 제외하고 남은 숫자들 (스택)
    leftover.push_back(s[s.length()-1]);
    leftover.push_back(s[s.length()-2]);

    for (int i=s.length()-3; i>=0; i--) {
        if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0') {
            c110s++;
            leftover.pop_back();
            leftover.pop_back();
            if (i-1 >= 0) leftover.push_back(s[i-1]);
            if (i-2 >= 0) leftover.push_back(s[i-2]);
            i-=2;
            continue;
        }
        else leftover.push_back(s[i]);
    }

    string res = {};
    while(leftover.size() >= 2) {
        cout << leftover.size() << " " << res << endl;
        // 110을 다 썼을 경우 단순히 스택 다 빼기
        if (c110s <= 0) {
            res.push_back(leftover.back());
            leftover.pop_back();
            continue;
        }

        // 11이 아닌 경우 걸러내기
        if (leftover[leftover.size()-1] == '0' || 
                leftover[leftover.size()-2] == '0') {
            res.push_back(leftover.back());
            leftover.pop_back();
            continue;
        }

        // 11인 경우 존재하는 모든 110을 이 구간에 때려넣기
        while(c110s > 0) {
            res.append("110");
            c110s--;
        }
    }

    while(!leftover.empty()) {
        res.push_back(leftover.back());
        leftover.pop_back();
    }
    
    return res;
}
    */