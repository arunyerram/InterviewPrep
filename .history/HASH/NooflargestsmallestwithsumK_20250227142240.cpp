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

int main() {
    int n = 6;
    int k = 5;
    vector<int> arr = {1, 2, 3, 4, 2, 5};
    int maxLength, minLength;
    pair<int,int>{maxLength, minLength} = findSubarraySizes(n, k, arr);
    int maxCount = countSubarraysWithLength(n, k, arr, maxLength);
    int minCount = countSubarraysWithLength(n, k, arr, minLength);

    cout << "Max Length: " << maxLength << " Count: " << maxCount << endl;
    cout << "Min Length: " << minLength << " Count: " << minCount << endl;

    return 0;
}










// Java   ;;;;--------

// import java.util.*;

// public class Main {

//     public static Pair<Integer, Integer> findSubarraySizes(int n, int k, int[] arr) {
//         Map<Integer, Integer> mp = new HashMap<>();
//         Map<Integer, Integer> mp2 = new HashMap<>();
//         mp.put(0, 0);
//         int pSum = 0;
//         int maxLength = 0;
//         int minLength = Integer.MAX_VALUE;

//         for (int j = 1; j <= n; j++) {
//             pSum += arr[j - 1];
//             int x = pSum - k;

//             if (mp.containsKey(x)) {
//                 int i = mp.get(x) + 1;
//                 int curLength = j - i + 1;
//                 if (curLength > maxLength) {
//                     maxLength = curLength;
//                 }
//             }

//             if (mp2.containsKey(x)) {
//                 int i = mp2.get(x) + 1;
//                 int curLength = j - i + 1;
//                 if (curLength < minLength) {
//                     minLength = curLength;
//                 }
//             }

//             mp.putIfAbsent(pSum, j);
//             mp2.put(pSum, j);
//         }

//         return new Pair<>(maxLength, minLength);
//     }

//     public static int countSubarraysWithLength(int n, int k, int[] arr, int targetLength) {
//         if (targetLength == 0) return 0;
//         int count = 0;
//         int windowSum = 0;

//         for (int j = 0; j < targetLength; j++) {
//             windowSum += arr[j];
//         }

//         if (windowSum == k) {
//             count++;
//         }

//         for (int j = targetLength; j < n; j++) {
//             windowSum += arr[j] - arr[j - targetLength];
//             if (windowSum == k) {
//                 count++;
//             }
//         }

//         return count;
//     }

//     public static void main(String[] args) {
//         int n = 6;
//         int k = 5;
//         int[] arr = {1, 2, 3, 4, 2, 5};

//         Pair<Integer, Integer> sizes = findSubarraySizes(n, k, arr);
//         int maxLength = sizes.getKey();
//         int minLength = sizes.getValue();

//         int maxCount = countSubarraysWithLength(n, k, arr, maxLength);
//         int minCount = countSubarraysWithLength(n, k, arr, minLength);

//         System.out.println("Max Length: " + maxLength + " Count: " + maxCount);
//         System.out.println("Min Length: " + minLength + " Count: " + minCount);
//     }
// }

// class Pair<K, V> {
//     private K key;
//     private V value;

//     public Pair(K key, V value) {
//         this.key = key;
//         this.value = value;
//     }

//     public K getKey() {
//         return key;
//     }

//     public V getValue() {
//         return value;
//     }
// }



// Python ---------- 

