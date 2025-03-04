#include <bits/stdc++.h>
using namespace std;

pair<int, int> findSubarraySizes(int n, int k, const vector<int>& arr) {
    unordered_map<int, int> mp;
    unordered_map<int, int> mp2;
    mp[0] = 0;
    int pSum = 0;
    int maxLength = 0;
    int minLength = INT_MAX;

    for (int j = 1; j <= n; j++) {
        pSum += arr[j - 1];
        int x = pSum - k;

        if (mp.find(x) != mp.end()) {
            int i = mp[x] + 1;
            int curLength = j - i + 1;
            if (curLength > maxLength) {
                maxLength = curLength;
            }
        }

        if (mp2.find(x) != mp2.end()) {
            int i = mp2[x] + 1;
            int curLength = j - i + 1;
            if (curLength < minLength) {
                minLength = curLength;
            }
        }

        if (mp.find(pSum) == mp.end())
            mp[pSum] = j;

        mp2[pSum] = j;
    }

    return {maxLength, minLength};
}

int countSubarraysWithLength(int n, int k, const vector<int>& arr, int targetLength) {
    if (targetLength == 0) return 0;
    int count = 0;
    int windowSum = 0;

    for (int j = 0; j < targetLength; j++) {
        windowSum += arr[j];
    }

    if (windowSum == k) {
        count++;
    }

    for (int j = targetLength; j < n; j++) {
        windowSum += arr[j] - arr[j - targetLength];
        if (windowSum == k) {
            count++;
        }
    }

    return count;
}

