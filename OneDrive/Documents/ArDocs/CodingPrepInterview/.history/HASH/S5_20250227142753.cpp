#include <iostream>
#include <vector>

using namespace std;

vector<int> prefixSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    return prefix;
}

int optimizedSum(const vector<int>& prefix, int l, int r) {
    return prefix[r] - prefix[l - 1];
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> prefix = prefixSum(nums);

    int l = 3, r = 7; // Example range [l, r]
    cout << "Optimized Sum: " << optimizedSum(prefix, l, r) << endl;

    return 0;
}











// java -------


// import java.util.*;

// public class PrefixSum {

//     static int[] prefixSum(int[] nums) {
//         int n = nums.length;
//         int[] prefix = new int[n + 1];
//         for (int i = 1; i <= n; ++i) {
//             prefix[i] = prefix[i - 1] + nums[i];
//         }
//         return prefix;
//     }

//     static int optimizedSum(int[] prefix, int l, int r) {
//         return prefix[r] - prefix[l - 1];
//     }

//     public static void main(String[] args) {
//         int[] nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//         int[] prefix = prefixSum(nums);

//         int l = 3, r = 7; // Example range [l, r]
//         System.out.println("Optimized Sum: " + optimizedSum(prefix, l, r));
//     }
// }
// /* package whatever; // don't place package name! */

// import java.util.*;
// import java.lang.*;
// import java.io.*;

// /* Name of the class has to be "Main" only if the class is public. */
// class Ideone
// {
// 	public static void main (String[] args) throws java.lang.Exception
// 	{
// 		// your code goes here
// 	}
// }




// ---------PYTHON -------


// def prefix_sum(nums):
//     prefix = [0] * (len(nums) + 1)
//     for i in range(1, len(nums)):
//         prefix[i] = prefix[i - 1] + nums[i]
//     return prefix

// def optimized_sum(prefix, l, r):
//     return prefix[r] - prefix[l - 1]

// nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// prefix = prefix_sum(nums)
// l, r = 3, 7  # Example range [l, r]
// print("Optimized Sum:", optimized_sum(prefix, l, r))
