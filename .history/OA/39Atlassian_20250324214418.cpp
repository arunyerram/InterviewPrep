#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;  // Read the value of n

    std::vector<int> b(n);  // Initialize a vector b of size n
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int tot_sum = 0;
    int c = 0;

    // Calculate the total sum of the elements in b
    for (int i = 0; i < n; i++) {
        tot_sum += b[i];
    }

    // Check if the total sum is divisible by 3
    if (tot_sum % 3 == 0) {
        std::unordered_map<int, int> prefix_sum_count;  // hashmap to store frequency of prefix sums
        int prefix_sum = 0;
        int y = tot_sum / 3;
        
        for (int i = 0; i < n - 1; i++) {
            prefix_sum += b[i];  // Sum of first i elements






            
            // If prefix_sum equals 2*y, check how many times y has occurred so far
            if (prefix_sum == 2 * y) {
                c += prefix_sum_count[y];  // Add the frequency of prefix_sum / 2 (which is y) to count
            }

            // Increment the frequency of the current prefix_sum
            prefix_sum_count[prefix_sum]++;
        }
    }

    std::cout << c << std::endl;  // Output the value of c

    return 0;
}






