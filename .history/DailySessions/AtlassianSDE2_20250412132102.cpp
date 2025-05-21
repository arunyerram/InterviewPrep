// Understanding of the problem:-> You are given “B” queries; you have to perform some of them in order ; and make your initial integer 1 as large as possible! 

// -> + x 
// -> - x 
// -> * x 
// ->/ x


// ->N => multiply with -1;

// Greedy :-> Only perform + and * -> they guarantee to give the best answer in most cases. 

// ->”Too much negative energy can be converted to big positive energy in an instant by “N” operation.”



// dp[..........]

// dp_max[i] = maximum energy you are getting by doing some of the first i operations. 

// dp_min[i] = minimum energy you are getting by doing some of the first i operations. 

// if(+)

// Dpi_max[i] = max(dpi_max[i-1] + x ; dpi_max[i-1]) 

// if(*)
// Dpi_max[i] = max(dpi_max[i-1]*x ; dpi_max[i-1]) 

// if(-)
// dpi_max[i] = max(dpi_max[i-1] - x ; dpi_max[i-1]) 

// if(/)
// dpi_max[i] = max(dpi_max[i-1] /x ; dpi_max[i-1])

// if(N)

// Dpi_max[i] = max(dpi_max[i-1] ; -1*dpi_max[i-1] ; -1*dpi_min[i-1])



// C++ https://ideone.com/007vpq 
// Java. https://ideone.com/ZhJtFx 
// Py https://ideone.com/5pBJ4N 

// TC : O(N).
// SC ; O(N). 




#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


// max sum obtained to get best sum till index i;

// min sum obtained to get best sum till index i;
// dp[i][0] = max sum obtained to get best sum till index i;
// dp[i][1] = min sum obtained to get best sum till index i;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    while(n--){ 
        ll m;
        cin>>m;

        ll i;

        ll dp_mx[m+1];
        ll dp_mn[m + 1];
        dp_mx[0] = 1;
        dp_mn[0] = 1;
        
        for(int i=1;i<)
    }
}
