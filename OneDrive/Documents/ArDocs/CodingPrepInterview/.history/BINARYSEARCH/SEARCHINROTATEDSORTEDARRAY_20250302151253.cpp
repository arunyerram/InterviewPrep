class Solution {
    public:
        int search(vector<int>& input, int target) {
            int lo = 0;
            int hi = input.size()-1;
    
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(input[mid]==target) return mid;
    
                if(input[mid] >= input[lo]) {
                    if(target >= input[lo] and target <= input[mid]) {
                        hi = mid - 1;
                    }    else {
                        lo = mid + 1; 
                    }
                }else {
                    if(target >= input[mid] and target <= input[hi]) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
            }return -1;
        }
    };