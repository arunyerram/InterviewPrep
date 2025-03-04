#include <iostream>
#include <vector>
#include <unordered_map>

int countPairsOptimized(const std::vector<int>& b, int k) {
    int count = 0;
    std::unordered_map<int, int> freqMap;
    for (int j = 0; j < b.size(); ++j) {
        int target = b[j] + k;
        if (freqMap.find(target) != freqMap.end()) {
            count += freqMap[target];
        }
        freqMap[b[j]]++;
    }
    return count;
}

int main() {
    std::vector<int> b = {1, 5, 3, 4, 2};
    int k = 2;
    std::cout << "Count of pairs: " << countPairsOptimized(b, k) << std::endl;
    return 0;
}




import java.util.HashMap;
import java.util.Map;

public class Main {
    public static int countPairsOptimized(int[] b, int k) {
        int count = 0;
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int j = 0; j < b.length; ++j) {
            int target = b[j] + k;
            if (freqMap.containsKey(target)) {
                count += freqMap.get(target);
            }
            freqMap.put(b[j], freqMap.getOrDefault(b[j], 0) + 1);
        }
        return count;
    }

    public static void main(String[] args) {
        int[] b = {1, 5, 3, 4, 2};
        int k = 2;
        System.out.println("Count of pairs: " + countPairsOptimized(b, k));
    }
}
