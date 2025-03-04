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


