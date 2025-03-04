#include <iostream>
#include <unordered_map>
#include <vector>

int countPairs(const std::vector<int>& arr, int k) {
    std::unordered_map<int, int> freq;
    int count = 0;

    for (int j = 0; j < arr.size(); ++j) {
        int complement = k - arr[j];
        if (freq.find(complement) != freq.end()) {
            count += freq[complement];
        }
        freq[arr[j]]++;
    }

    return count;
}

int main() {
    std::vector<int> arr = {1, 5, 7, -1, 5};
    int k = 6;
    std::cout << "Count of pairs: " << countPairs(arr, k) << std::endl;
    return 0;
}


// -------JAVA --------


// import java.util.*;

// public class Main {
//     static int countPairsWithSum(int[] b, int k) {
//         int count = 0;
//         Map<Integer, Integer> seen = new HashMap<>();
        
//         for (int j = 0; j < b.length; ++j) {
//             int complement = k - b[j];
//             if (seen.containsKey(complement)) {
//                 count += seen.get(complement); 
//             }
//             seen.put(b[j], j);
//         }
        
//         return count;
//     }

//     public static void main(String[] args) {
//         int[] b = {1, 2, 3, 4, 5};
//         int k = 6;
//         int count = countPairsWithSum(b, k);
        
//         System.out.println("Count of pairs with sum " + k + " is: " + count);
//     }
// }


// -------PYTHON -------


// def count_pairs_with_sum(b, k):
//     count = 0
//     seen = {}
    
//     for num in b:
//         complement = k - num
//         if complement in seen:
//             count += seen[complement]
//         seen[num] = True
        
//     return count

// if __name__ == "__main__":
//     b = [1, 2, 3, 4, 5]
//     k = 6
//     count = count_pairs_with_sum(b, k)
    
//     print("Count of pairs with sum", k, "is:", count)
