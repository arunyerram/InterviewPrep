#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int n ; 
   cin>>n ; 
   int a[n+1]={0};  // declaring the array; //using 1-based indexing
   int i = 1;
   while(i<=n)
   {
      cin>>a[i];
      i++;
   }
   // Calculate subset with maximum sum such that no two elements are adjacent
   // Setp 1: declare an dp array
   int dp[n+1]={0};
   int l = 0;
   dp[1] = max(a[1],l);
   dp[2] = max(a[1],max(a[2],l));
   // we calculated the formula dp[i] = max(dp[i-1],a[i]+dp[i-2])
   i = 3;
   while(i<=n)
   {
   //   dp[i] = max(dp[i-1],a[i] + dp[i-2]);
   dp[i] = max(dp[i-1],)
     i++;
   }

   cout<<dp[n];
   return 0;
}