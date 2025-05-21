#include <bits/stdc++.h>
using namespace std;

void recurse(string &s, int k, string &minStr, int idx) {
    if (k == 0) return;

    int n = s.size();
    char minChar = *min_element(s.begin() + idx, s.end());

    if (minChar != s[idx]) k--;

    for (int i = n - 1; i >= idx; --i) {
        if (s[i] == minChar) {
            swap(s[idx], s[i]);

            if (s < minStr) minStr = s;

            recurse(s, k, minStr, idx + 1);
            swap(s[idx], s[i]);
        }
    }
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    if (s.empty()) {
        cout << s << endl;
        return 0;
    }

    string minStr = s;
    recurse(s, k, minStr, 0);
    cout << minStr << endl;

    return 0;
}
