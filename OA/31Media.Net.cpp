
#include<bits/stdc++.h>
using namespace std;    

#include <bits/stdc++.h>
using namespace std;

int fun(vector< int > & A, int B) {
  int n = A.size();
  int suff[n + 1];
  suff[n] = 0;
  suff[n - 1] = A[n - 1];
  for (int i = n - 2; i >= 0; i--)
    suff[i] = A[i] + suff[i + 1];
  int prefSum = 0;
  int ans = suff[n - B];
  for (int i = 0; i < B; i++) {
    prefSum = prefSum + A[i];
    int suffSum = suff[n - B + (i + 1)];
    ans = max(ans, prefSum + suffSum);
  }
  return ans;
}
int solve(vector< int > & A, int B) {
  return fun(A,B);
}
int main()
{
	vector<int>A={5, -2, 3,1,2};
	int B=3;
	cout<<solve(A,B);
	return 0;
}