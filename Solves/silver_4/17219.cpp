#include <iostream>
#include <map>
#include <string>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

map<string, string> PW;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    rep(i,0,N) {
        string a, b;
        cin >> a >> b;
        PW[a] = b;
    }
    rep(i, 0, M) {
        string a;
        cin >> a;
        cout << PW.find(a)->second << '\n';
    }
    return 0;
}
