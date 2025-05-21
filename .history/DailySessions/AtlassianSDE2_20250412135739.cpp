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
        
        for(i=1;i<=m;i++){
            char c;
            cin>>c;
            if(c == '+'){
                ll e;
                cin>>e;
                dp_mx[i] = max({dp_mx[i-1] + e,dp_mn[i-1]  + e,dp_mx[i-1]});
                dp_mn[i] = min({dp_mn[i-1] + e,dp_mx[i-1]  + e,dp_mn[i-1]});
            }else if(c == '-'){
                ll e;
                cin>>e;
                dp_mx[i] = max({dp_mx[i-1]-e,dp_mx[i-1],dp_mn[i-1]-e});
                dp_mn[i] = min({dp_mn[i-1]-e,dp_mn[i-1],dp_mx[i-1]-e});
            }else if(c == '*'){
                ll e;
                cin>>e;
                dp_mx[i] = max({dp_mx[i-1]*e,dp_mx[i-1],dp_mn[i-1]*e});
                dp_mn[i] = min({dp_mn[i-1]*e,dp_mn[i-1],dp_mx[i-1]*e});
            }else if(c == '/'){
                ll e;
                cin>>e;
                dp_mx[i] = max({dp_mx[i-1]/e,dp_mx[i-1],dp_mn[i-1]/e});
                dp_mn[i] = min({dp_mx[i-1]/e,dp_mn[i-1],dp_mn[i-1]/e});
            }else{
                dp_mx[i] = max({dp_mx[i-1]*(-1),dp_mn[i-1]*(-1),dp_mx[i-1]});
                dp_mn[i] = min({dp_mn[i-1]*(-1),dp_mx[i-1]*(-1),dp_mn[i-1]});
            }
        }cout<<dp_mx[m]<<endl;
    }
    return 0;
}

















import java.util.Scanner;

public class Main {
    public static long max(long a, long b, long c) {
        return Math.max(a, Math.max(b, c));
    }

    public static long min(long a, long b, long c) {
        return Math.min(a, Math.min(b, c));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character after reading 't'
        while (t-- > 0) {
            long b = scanner.nextLong();
            scanner.nextLine(); // Consume the newline character after reading 'b'
            long[] dp1 = new long[(int) (b + 1)];
            long[] dp2 = new long[(int) (b + 1)];
            dp1[0] = 1;
            dp2[0] = dp1[0];
            for (long i = 1; i <= b; i++) {
                String line = scanner.nextLine();
                char g = line.charAt(0);
                long e = 0;
                if (line.length() > 2) {
                    e = Long.parseLong(line.substring(2)); // Extract the integer value
                }
                if (g == '+') {
                    dp1[(int) i] = max(dp1[(int) (i - 1)] + e, dp2[(int) (i - 1)] + e, dp1[(int) (i - 1)]);
                    dp2[(int) i] = min(dp1[(int) (i - 1)] + e, dp2[(int) (i - 1)] + e, dp2[(int) (i - 1)]);
                } else if (g == '-') {
                    dp1[(int) i] = max(dp1[(int) (i - 1)] - e, dp2[(int) (i - 1)] - e, dp1[(int) (i - 1)]);
                    dp2[(int) i] = min(dp1[(int) (i - 1)] - e, dp2[(int) (i - 1)] - e, dp2[(int) (i - 1)]);
                } else if (g == '*') {
                    dp1[(int) i] = max(dp1[(int) (i - 1)] * e, dp2[(int) (i - 1)] * e, dp1[(int) (i - 1)]);
                    dp2[(int) i] = min(dp1[(int) (i - 1)] * e, dp2[(int) (i - 1)] * e, dp2[(int) (i - 1)]);
                } else if (g == '/') {
                    dp1[(int) i] = max(dp1[(int) (i - 1)] / e, dp2[(int) (i - 1)] / e, dp1[(int) (i - 1)]);
                    dp2[(int) i] = min(dp1[(int) (i - 1)] / e, dp2[(int) (i - 1)] / e, dp2[(int) (i - 1)]);
                } else {
                    dp1[(int) i] = max(-1 * dp1[(int) (i - 1)], -1 * dp2[(int) (i - 1)], dp1[(int) (i - 1)]);
                    dp2[(int) i] = min(-1 * dp1[(int) (i - 1)], -1 * dp2[(int) (i - 1)], dp2[(int) (i - 1)]);
                }
            }
            System.out.println(dp1[(int) b]);
        }
        scanner.close();
    }
}
