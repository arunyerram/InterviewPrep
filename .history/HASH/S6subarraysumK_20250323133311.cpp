#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// S6--------------
int countSubarraysOptimized(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;
    int mn = arr.size();
    prefixSumCount[0] = 1;
    map<int,int>mp;
    mp[0] = 1;
    for (int i=0 ;i<arr.size();i++) {
        sum += arr[i];

        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
            mn = min(mn,);
        }

        prefixSumCount[sum]++;
        mp[sum] = i;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    cout << "Number of subarrays with sum " << k << ": " << countSubarraysOptimized(arr, k) << endl;
    return 0;
}







// import java.util.*;

// public class Main {
//     public static int countSubarraysOptimized(int[] arr, int k) {
//         Map<Integer, Integer> prefixSumCount = new HashMap<>();
//         int sum = 0, count = 0;

//         prefixSumCount.put(0, 1);

//         for (int num : arr) {
//             sum += num;

//             if (prefixSumCount.containsKey(sum - k)) {
//                 count += prefixSumCount.get(sum - k);
//             }

//             prefixSumCount.put(sum, prefixSumCount.getOrDefault(sum, 0) + 1);
//         }

//         return count;
//     }

//     public static void main(String[] args) {
//         int[] arr = {1, 2, 3, 4, 5};
//         int k = 5;
//         System.out.println("Number of subarrays with sum " + k + ": " + countSubarraysOptimized(arr, k));
//     }
// }



// def count_subarrays_optimized(arr, k):
//     from collections import defaultdict

//     prefix_sum_count = defaultdict(int)
//     sum = 0
//     count = 0

//     prefix_sum_count[0] = 1

//     for num in arr:
//         sum += num

//         if (sum - k) in prefix_sum_count:
//             count += prefix_sum_count[sum - k]

//         prefix_sum_count[sum] += 1

//     return count

// arr = [1, 2, 3, 4, 5]
// k = 5
// print("Number of subarrays with sum {}: {}".format(k, count_subarrays_optimized(arr, k)))
