You are given a string S representing a positive integer and an integer k. Your task is to find the smallest possible number that can be formed by performing at most k swaps between any two digits of the string.
If k == 0, return the original number.
If the number is already the smallest possible permutation, return it as-is.
If the input is null or empty, return it unchanged.

A swap operation means exchanging the positions of any two digits (not necessarily adjacent). Each swap counts as one operation. The goal is to minimize the number.

Input Format:
-----------
A string S of digits (1 ≤ S.length ≤ 10)
An integer k (0 ≤ k ≤ 10) representing the number of allowed swaps.

Output Format:
------------
A string representing the smallest number possible after performing at most k swaps.

Constraints:
--------------
1 ≤ length(S) ≤ 10
0 ≤ k ≤ 10
Digits are in the range '0' to '9'
No leading zeros in input unless the number is exactly "0"
Each swap counts as 1 operation, regardless of position

Sample Input-1:
------------
934651
2

Sample Output-1:
----------------
134569

Sample Input-2:
-------------
11111
3
Sample Output-2:
--------------
11111



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
