#include <iostream>
#include <vector>
#include <cmath>  // For abs() function
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;  // Read n and k
    string s;
    cin >> s;  // Read the input string

    vector<int> dp(n, 1);  // DP array to store the length of the largest valid substring ending at index i
    int max_len = 1;  // To store the maximum length of valid substring
    int max_index = 0;  // To store the index where max_len ends

    // Fill the dp array
    for (int i = 1; i < n; i++) {
        if (abs(s[i] - s[i - 1]) <= k) {
            dp[i] = dp[i - 1] + 1;  // Extend the valid substring
        } else {
            dp[i] = 1;  // Reset to 1 if the condition doesn't hold
        }

        // Update max_len and max_index if we find a longer valid substring
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_index = i;
        }
    }
    

    // Print the largest valid substring
    // int start_index = max_index - max_len + 1;
    cout << s.substr(max_index, max_len) << endl;

    return 0;
}
