#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSubarrays(int n, int x, int y, int z, int w, int b) {
        int count = 0;  // Count of valid subarrays
        map<tuple<int, int, int, int>, int> freq;  // Frequency map to store counts of (d1, d2, d3, d4)
        freq[{0, 0, 0, 0}] = 1;  // Base case: (d1, d2, d3, d4) has been achieved once

        int cx = 0, cy = 0, cz = 0, cw = 0, cb = 0;  // Counters for x, y, z, w, b

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;  // Taking input for each element of the array

            // Update counters based on the value
            if (val == x) cx++;
            else if (val == y) cy++;
            else if (val == z) cz++;
            else if (val == w) cw++;
            else if (val == b) cb++;

            // Compute differences
            int d1 = cy - cx;  // First condition difference
            int d2 = cz - cy;  // Second condition difference
            int d3 = cw - cz;  // Third condition difference
            int d4 = cb - cw;  // Fourth condition difference

            // Increment count based on how many times (d1, d2, d3, d4) was achieved
            count += freq[{d1, d2, d3, d4}];

            // Update frequency of (d1, d2, d3, d4)
            freq[{d1, d2, d3, d4}]++;
        }
        return count;
    }
};

int main() {
    int n, x, y, z, w, b;
    cin >> n >> x >> y >> z >> w >> b;  // Input the size and the distinct integers
    Solution sol;
    cout << sol.countValidSubarrays(n, x, y, z, w, b) << endl;  // Output the result
    return 0;
}
