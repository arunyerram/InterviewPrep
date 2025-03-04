#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    int k;
    cin >> k;
    int cnt = 0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(arr[i] + k) != mp.end()){
            cnt++;
        }

        if(k != 0 && mp.find(arr[i] - k) != mp.end()){
            cnt++;
        }
        mp[arr[i]]++;
    }return 0;
}












//  JAVA---------------

// import java.util.HashMap;

// public class Main {
//     public static int countPairsWithDifferenceK(int[] b, int k) {
//         HashMap<Integer, Integer> freq = new HashMap<>();
//         int count = 0;

//         for (int j = 0; j < b.length; ++j) {
//             if (freq.containsKey(b[j] - k)) {
//                 count += freq.get(b[j] - k);
//             }
//             if (k != 0 && freq.containsKey(b[j] + k)) { // to avoid double counting when k = 0
//                 count += freq.get(b[j] + k);
//             }

//             freq.put(b[j], freq.getOrDefault(b[j], 0) + 1);
//         }

//         return count;
//     }

//     public static void main(String[] args) {
//         int[] b = {1, 5, 3, 4, 2};
//         int k = 2;
//         System.out.println(countPairsWithDifferenceK(b, k)); // Output should be the number of pairs with difference k
//     }
// }




// ------ PYTHON ---------

def count_pairs_with_difference_k(b, k):
    count = 0
    freq = {}

    for j in range(len(b)):
        if b[j] - k in freq:
            count += freq[b[j] - k]
        if k != 0 and b[j] + k in freq:  # to avoid double counting when k = 0
            count += freq[b[j] + k]
        
        if b[j] in freq:
            freq[b[j]] += 1
        else:
            freq[b[j]] = 1

    return count

# Example usage:
b = [1, 5, 3, 4, 2]
k = 2
print(count_pairs_with_difference_k(b, k))  # Output should be the number of pairs with difference k
