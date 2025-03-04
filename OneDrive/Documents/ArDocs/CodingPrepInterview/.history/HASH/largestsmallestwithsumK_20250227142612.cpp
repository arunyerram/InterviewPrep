#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//  S7  ..............

pair<int, int> largestSubarraySumK(const vector<int>& nums, int k) {
    unordered_map<int, int> sumIndexMap;
    sumIndexMap[0] = -1;//This is imaginary index -1 taken for sum 0 as initially sum is 0 and index where it is occuring is set to be -1.
    int currentSum = 0;
    int maxLen = 0;
    pair<int, int> result = {-1, -1};

    for (int j = 0; j < nums.size(); ++j) {
        currentSum += nums[j];

        if (sumIndexMap.find(currentSum - k) != sumIndexMap.end()) {
            int length = j - sumIndexMap[currentSum - k];
            if (length > maxLen) {
                maxLen = length;
                result = {sumIndexMap[currentSum - k] + 1, j};
            }
        }

        if (sumIndexMap.find(currentSum) == sumIndexMap.end()) {//We are updating only when current sum occurs first time as we want Longest subarray with sum k
            sumIndexMap[currentSum] = j;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, -1, -4};
    int k = 9;
    pair<int, int> result = largestSubarraySumK(nums, k);
    if (result.first != -1) {
        cout << "Largest subarray with sum " << k << " is from index " << result.first << " to " << result.second << endl;
    } else {
        cout << "No subarray with sum " << k << endl;
    }
    return 0;
}





// import java.util.*;

// public class Main {
//     public static int[] largestSubarraySumK(int[] nums, int k) {
//         int maxLen = 0;
//         int[] result = {-1, -1};

//         for (int i = 0; i < nums.length; ++i) {
//             int currentSum = 0;
//             for (int j = i; j < nums.length; ++j) {
//                 currentSum += nums[j];
//                 if (currentSum == k && (j - i + 1) > maxLen) {
//                     maxLen = j - i + 1;
//                     result[0] = i + 1;  // 1-based index
//                     result[1] = j + 1;
//                 }
//             }
//         }
//         return result;
//     }

//     public static void main(String[] args) {
//         int[] nums = {1, 2, 3, 4, 5, -1, 6};
//         int k = 9;
//         int[] result = largestSubarraySumK(nums, k);
//         if (result[0] != -1) {
//             System.out.println("Largest subarray with sum " + k + " is from index " + result[0] + " to " + result[1]);
//         } else {
//             System.out.println("No subarray with sum " + k);
//         }
//     }
// }





// def largest_subarray_sum_k(nums, k):
//     sum_index_map = {0: -1}  # Imaginary index -1 for sum 0.
//     current_sum = 0
//     max_len = 0
//     result = (-1, -1)

//     for j in range(len(nums)):
//         current_sum += nums[j]

//         if current_sum - k in sum_index_map:
//             length = j - sum_index_map[current_sum - k]
//             if length > max_len:
//                 max_len = length
//                 result = (sum_index_map[current_sum - k] + 1, j)

//         if current_sum not in sum_index_map:
//             sum_index_map[current_sum] = j

//     return result

// # Test the function
// nums = [1, 2, 3, 4, 5, -1, -4]
// k = 9
// result = largest_subarray_sum_k(nums, k)
// if result[0] != -1:
//     print(f"Largest subarray with sum {k} is from index {result[0]} to {result[1]}")
// else:
//     print(f"No subarray with sum {k}")
