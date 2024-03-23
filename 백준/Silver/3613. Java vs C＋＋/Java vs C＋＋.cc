#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, ans = "";
    cin >> s;

    bool cpp = false, java = false, e = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <='Z') {
            if (i == 0) {
                e = true;
                break;
            }
            ans += '_';
            ans += s[i] + ('a' - 'A');
            cpp = true;
        }
        else if (s[i] == '_') {
            if (s[i+1] < 'a' || i == 0) {
                e = true;
                break;
            }
            ans += s[++i] - ('a' - 'A');
            java = true;
        }
        else
            ans += s[i];
    }

    if ((cpp && java) || e) cout << "Error!";
    else cout << ans;
}
