#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      int maxLen(vector<int>& arr) {
          // code here
          int n = arr.size();
          int mx = 0;
          
          map<int,int>mp;
          int sum = 0;
          mp[0] = -1;
          for(auto i=0;i<n;i++){
              sum += arr[i];
              
              if(mp.find(sum) != mp.end()){
                  mx = max(mx,i - mp[sum]);
              }else{
                  mp[sum] = i;
              }
          }
          return mx;
      }
  };



// import java.util.*;

//   class Solution {
//       public int maxLen(int[] arr) {
//           int n = arr.length;
//           int mx = 0;
          
//           Map<Integer, Integer> mp = new HashMap<>();
//           int sum = 0;
//           mp.put(0, -1);
  
//           for (int i = 0; i < n; i++) {
//               sum += arr[i];
  
//               if (mp.containsKey(sum)) {
//                   mx = Math.max(mx, i - mp.get(sum));
//               } else {
//                   mp.put(sum, i);
//               }
//           }
//           return mx;
//       }
  
//       public static void main(String[] args) {
//           Solution sol = new Solution();
//           int[] arr = {1, -1, 3, 2, -2, -3, 3};
//           System.out.println(sol.maxLen(arr));  // Example call
//       }
//   }
  


//   def max_len(arr):
//     n = len(arr)
//     mx = 0
    
//     mp = {0: -1}
//     total_sum = 0

//     for i in range(n):
//         total_sum += arr[i]

//         if total_sum in mp:
//             mx = max(mx, i - mp[total_sum])
//         else:
//             mp[total_sum] = i
    
//     return mx

// # Example usage
// arr = [1, -1, 3, 2, -2, -3, 3]
// print(max_len(arr))  # Example call
