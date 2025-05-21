#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Check if brackets match
bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Validate full expression
bool isValid(string &s) {
    stack<char> st;
    for (char c : s) {
        if (c == '{' || c == '(' || c == '[')
            st.push(c);
        else {
            if (st.empty() || !isMatch(st.top(), c))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

// Extract outermost valid bracket expressions
vector<string> extractValid(string &s) {
    vector<string> res;
    stack<pair<char, int>> st;
    int n = s.size();

    for (int i = 0; i < n; ) {
        char c = s[i];
        if (c == '{' || c == '(' || c == '[') {
            st.push({c, i});
            i++;
        } else if (c == '}' || c == ')' || c == ']') {
            if (!st.empty() && isMatch(st.top().first, c)) {
                int start = st.top().second;
                st.pop();
                string sub = s.substr(start, i - start + 1);
                if (isValid(sub))
                    res.push_back(sub);
                i = start + 1; // Move to the next character after the closing bracket
            } else {
                // Invalid bracket found, clear stack to skip nested corruption
                while (!st.empty()) st.pop();
                i++;    
            }
        }
    }
    return res;
}

int main() {
    string input = "{[]}{}(){()}{[)}";
    vector<string> valid = extractValid(input);
    for (const string &s : valid) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}


