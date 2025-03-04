class Solution {
    public:
      int nthRoot(int n, int m) {
          // Code here.
          int i = 1;
          int j = m;
          
          while(i <= j){
              int mid = (i+j)/2;
              if(pow(mid,n) == m)return mid;
              if(pow(mid,n) > m){
                  j = mid-1;
              }else{
                  i = mid+1;
              }
          }return -1;
      }
  };