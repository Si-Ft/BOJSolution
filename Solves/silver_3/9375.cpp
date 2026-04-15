#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

void runTest(int tc);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    rep(tc,0,TC) runTest(tc);
    return 0;
}

void runTest(int tc) {
    map<string, int> m;
    vector<string> dict;
    int n;
    cin >> n;
    rep(i,0,n) {
        string name, type;
        cin >> name >> type;
        if (m.find(type) == m.end()) dict.push_back(type);
        m[type]++;
    }

    int ans = 1;
    for (string type : dict) {
        ans *= (m[type] + 1);
    }
    cout << ans - 1 << "\n";
}