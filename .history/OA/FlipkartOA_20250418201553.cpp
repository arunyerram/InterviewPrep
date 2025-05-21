#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n; 
        string st;
        cin >> st;

        // Find the first character from the left that is greater than a smaller character to its right
        int idx = -1;
        char c = st[0];

        for(int i = 1; i < n; ++i) {
            if(st[i] < c) {
                idx = i;      // index of the smallest character to swap
                c = st[i];    // update with smaller character
            }
        }

        if(idx != -1) {
            // Find the first position from left where current char > c
            for(int j = 0; j < idx; ++j) {
                if(st[j] > c) {
                    swap(st[j], st[idx]);
                    break;
                }
            }
        }
        cout << st << endl;
    }

    return 0;
}
