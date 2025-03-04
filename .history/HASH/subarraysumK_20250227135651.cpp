#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarraysOptimized(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;

    prefixSumCount[0] = 1;

    for (int num : arr) {
        sum += num;

        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }

        prefixSumCount[sum]++;
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



