#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

vector<string> extractValidBrackets(string s) {
    vector<string> result;
    stack<pair<char, int>> st;
    int n = s.size();

    for (int i = 0; i < n; ) {
        char c = s[i];
        if (c == '{' || c == '(' || c == '[') {
            st.push({c, i});
            i++;
        } else if (c == '}' || c == ')' || c == ']') {
            if (!st.empty()) {
                char open = st.top().first;
                int start = st.top().second;
                st.pop();
                string sub = s.substr(start, i - start + 1);
                if (isValid(sub))
                    result.push_back(sub);
            }i = (i + 1);
        }
    }
    return result;
}

int main() {
    string input = "{[]}{}(){()}{[)}";
    vector<string> valid = extractValidBrackets(input);
    for (string &s : valid) cout << s << " ";
    cout << "\n";
    return 0;
}
