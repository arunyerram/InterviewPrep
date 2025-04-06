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






// 4y   


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout<<"YES"<< endl
#define no cout<<"NO"<< endl
#define print(i) cout << i << endl

ll M = 1e9 + 7;

int solve(vector<int>nums) {

        int n = nums.size();
        int pre = nums[0] + nums[1]; // putting stick after 2 element
        int tot = 0; // to store total sum of array
        int post[n]; // postfix sum array
        int ans = 0;
        post[n-1] = nums[n-1];
        unordered_map<int, int>mp1;  // map to store occurrence while prefixing
        unordered_map<int, int>mp2; // map to store occurrence while postfixing

        mp2[nums[n-1]] = 1;
	
       // filling postfix array
        for(int i=n-2;i>= 0;i--){
        	post[i] = post[i+1] + nums[i];
        	mp2[post[i]] += 1;
        }

        tot = post[0];
        int y = tot/2;
        int x = y/2;
        
        

        mp1[nums[0]] = 1;
        mp1[nums[0] + nums[1]] += 1;

        mp2[post[0]]--;
        mp2[post[1]]--;

        for(int i=2;i<n;i++){
        	pre += nums[i];
        	mp1[pre] += 1;
        	mp2[post[i]]--;

        	if(pre == y){
        		int lp = mp1[x];
        		int rp = mp2[x];
        		ans += lp*rp;
        	}
        }
    
        return ans;
    }

int main() 
{
vector<int> nums = {4,2,1,0,-1,1,7,3,3,1,-3,3,7};
// 	vector<int> nums = {1,1,1,1};
	cout << solve(nums);
	return 0;
}

