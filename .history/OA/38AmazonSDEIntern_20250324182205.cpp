#include <bits/stdc++.h>
using namespace std;

// -> Please find the increasing subsequence of size - “3” - Return true if it exists; return false if it does not exist 


bool function(const std::vector<int>& b, int n) {
    std::vector<int> p(n + 1), s(n + 1);
    p[1] = b[1];
    s[n] = b[n];

    for (int i = 2; i <= n; i++) {
        p[i] = std::min(b[i], p[i - 1]);
    }

    for (int i = n - 1; i >= 1; i--) {
        s[i] = std::max(b[i], s[i + 1]);
    }

    for (int i = 2; i <= n - 1; i++) {
        if (p[i - 1] < b[i] && b[i] < s[i + 1]) {
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> b(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }

    bool result = function(b, n);
    std::cout << (result ? "True" : "False") << std::endl;

    return 0;
}



bool function(const std::vector<int>& b, int n) {
    std::vector<int> s(n + 1);
    s[n] = b[n];

    for (int i = n - 1; i >= 1; i--) {
        s[i] = std::max(b[i], s[i + 1]);
    }

    int p = b[1];
    for (int i = 2; i <= n - 1; i++) {
        if (p < b[i] && b[i] < s[i + 1]) {
            return true;
        }
        p = std::min(p, b[i]);
    }

    return false;
}




// HW :- Same as above question but the triplet should be of the form:- (b[i]+1==b[j] && b[j]+1==b[k]) => b[i]<b[j]<b[k] 

// HW :- Same as above question but the triplet should be of the form:- (b[i]+1==b[j] && b[j]+1==b[k]) => b[i]<b[j]<b[k] 



#include <bits/stdc++.h>
using namespace std;

bool boolConsecutiveTriplets(vector<int> nums){
	int n = nums.size();

	map<int, int> prefix;
	map<int, int> suffix;
	
	for(int i=1;i<=n;i++){
	    suffix[nums[i]]++;
	}
	
	for(int i = 2; i <= n-1; i++){
	    
	    suffix[nums[i]]--;
	    
		if(prefix.find(nums[i]-1) != prefix.end() and suffix.find(nums[i]+1) != suffix.end())
		return true;
		
	    prefix[nums[i]]++;
	}

	return false;
}

int main()
{
	int n;
	cin>>n;

	vector<int> nums(n+1);

	for(int index = 1; index <= n; index++){
		cin>>nums[index];
	}

	cout << boolConsecutiveTriplets(nums);

	return 0;
}