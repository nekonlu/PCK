#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define srep(i, s, n) for (int i = (s); i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;

// 括弧の整合性をチェックするコード
// https://qiita.com/drken/items/6a95b57d2e374a3d3292

bool check(const string &s){
    stack<int> st;
    vector<pair<int, int>> ps;

    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '(') {
            st.push(i);
        } else {
            if (st.empty()) {
                // ↑これは最初から')'であるかを判定する条件文
                //　最初が')'は間違いなくエラー
                cout << "error" << endl;
                return false;
            }
            int t = st.top();
            st.pop();
            ps.push_back({t, i});
        }
    }

    if(!st.empty()){
        cout << "too many (" << endl;
    }

    sort(ps.begin(), ps.end());
    for (int i = 0; i < (int)ps.size(); i++) {
        if(i) cout << ", ";
        cout << "(" << ps[i].first << ", " << ps[i].second << ")";
    }

    cout << endl;
    return true;
}

int main() {
    check("()()(()((())))");
}