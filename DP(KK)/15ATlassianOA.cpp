

// Link -> https://www.desiqna.in/15782/atlassian-oa-sde-1-freshers-hiring-ctc-75-lac 





// Understanding of the problem:-> You are given “B” queries; you have to perform some of them in order ; and make your initial integer 1 as large as possible! 

// -> + x 
// -> - x 
// -> * x 
// ->/ x
// ->N

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
#define rep(i, l, r) for ((i) = (l); (i) <=(r); (i)++)
#define rep1(i, r, l) for ((i) = (r); (i) >=(l); (i)--)

ll max(ll a,ll b,ll c)
{
    return max(a,max(b,c)) ; 
}
ll min(ll a,ll b,ll c)
{
    return min(a,min(b,c)) ;
}

int main()
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL);
    cout.tie(NULL);
    ll t ; 
    cin>>t;
    while(t--)
    {
    ll b; 
    cin>>b ; 
    ll i ; 
    ll dp1[b+1];
    ll dp2[b+1];
    dp1[0]=1;
    dp2[0]=dp1[0];
    rep(i,1,b)
    {
        char g ; 
        cin>>g ; 
        if(g=='+')
        { ll e ; cin>>e;
            dp1[i] = max(dp1[i-1]+e,dp2[i-1]+e,dp1[i-1]) ; 
            dp2[i] = min(dp1[i-1]+e,dp2[i-1]+e,dp2[i-1]) ;   
        }
        else if(g=='-')
        { ll e ; cin>>e;
            dp1[i] = max(dp1[i-1]-e,dp2[i-1]-e,dp1[i-1]) ; 
            dp2[i] = min(dp1[i-1]-e,dp2[i-1]-e,dp2[i-1]) ; 
        }
        else if(g=='*')
        { ll e ; cin>>e;
            dp1[i] = max(dp1[i-1]*e,dp2[i-1]*e,dp1[i-1]) ; 
            dp2[i] = min(dp1[i-1]*e,dp2[i-1]*e,dp2[i-1]) ; 
        }
        else if(g=='/')
        { ll e ; cin>>e;
            dp1[i] = max(dp1[i-1]/e,dp2[i-1]/e,dp1[i-1]) ; 
            dp2[i] = min(dp1[i-1]/e,dp2[i-1]/e,dp2[i-1]) ; 
        }
        else{
            dp1[i] = max(-1*dp1[i-1],-1*dp2[i-1], dp1[i-1]) ; 
            dp2[i] = min(-1*dp1[i-1],-1*dp2[i-1], dp2[i-1]) ;
        }
    }
    cout<<dp1[b]; 
    cout<<"\n";    
}
	return 0;
}




// import java.util.Scanner;

// public class Main {
//     public static long max(long a, long b, long c) {
//         return Math.max(a, Math.max(b, c));
//     }

//     public static long min(long a, long b, long c) {
//         return Math.min(a, Math.min(b, c));
//     }

//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);
//         int t = scanner.nextInt();
//         scanner.nextLine(); // Consume the newline character after reading 't'
//         while (t-- > 0) {
//             long b = scanner.nextLong();
//             scanner.nextLine(); // Consume the newline character after reading 'b'
//             long[] dp1 = new long[(int) (b + 1)];
//             long[] dp2 = new long[(int) (b + 1)];
//             dp1[0] = 1;
//             dp2[0] = dp1[0];
//             for (long i = 1; i <= b; i++) {
//                 String line = scanner.nextLine();
//                 char g = line.charAt(0);
//                 long e = 0;
//                 if (line.length() > 2) {
//                     e = Long.parseLong(line.substring(2)); // Extract the integer value
//                 }
//                 if (g == '+') {
//                     dp1[(int) i] = max(dp1[(int) (i - 1)] + e, dp2[(int) (i - 1)] + e, dp1[(int) (i - 1)]);
//                     dp2[(int) i] = min(dp1[(int) (i - 1)] + e, dp2[(int) (i - 1)] + e, dp2[(int) (i - 1)]);
//                 } else if (g == '-') {
//                     dp1[(int) i] = max(dp1[(int) (i - 1)] - e, dp2[(int) (i - 1)] - e, dp1[(int) (i - 1)]);
//                     dp2[(int) i] = min(dp1[(int) (i - 1)] - e, dp2[(int) (i - 1)] - e, dp2[(int) (i - 1)]);
//                 } else if (g == '*') {
//                     dp1[(int) i] = max(dp1[(int) (i - 1)] * e, dp2[(int) (i - 1)] * e, dp1[(int) (i - 1)]);
//                     dp2[(int) i] = min(dp1[(int) (i - 1)] * e, dp2[(int) (i - 1)] * e, dp2[(int) (i - 1)]);
//                 } else if (g == '/') {
//                     dp1[(int) i] = max(dp1[(int) (i - 1)] / e, dp2[(int) (i - 1)] / e, dp1[(int) (i - 1)]);
//                     dp2[(int) i] = min(dp1[(int) (i - 1)] / e, dp2[(int) (i - 1)] / e, dp2[(int) (i - 1)]);
//                 } else {
//                     dp1[(int) i] = max(-1 * dp1[(int) (i - 1)], -1 * dp2[(int) (i - 1)], dp1[(int) (i - 1)]);
//                     dp2[(int) i] = min(-1 * dp1[(int) (i - 1)], -1 * dp2[(int) (i - 1)], dp2[(int) (i - 1)]);
//                 }
//             }
//             System.out.println(dp1[(int) b]);
//         }
//         scanner.close();
//     }
// }







// def maximize_minimize(b, operations):
//     dp1 = [0] * (b + 1)
//     dp2 = [0] * (b + 1)
//     dp1[0] = 1
//     dp2[0] = dp1[0]

//     for i in range(1, b + 1):
//         g, e = operations[i - 1]
//         if g == '+':
//             dp1[i] = max(dp1[i - 1] + e, dp2[i - 1] + e, dp1[i - 1])
//             dp2[i] = min(dp1[i - 1] + e, dp2[i - 1] + e, dp2[i - 1])
//         elif g == '-':
//             dp1[i] = max(dp1[i - 1] - e, dp2[i - 1] - e, dp1[i - 1])
//             dp2[i] = min(dp1[i - 1] - e, dp2[i - 1] - e, dp2[i - 1])
//         elif g == '*':
//             dp1[i] = max(dp1[i - 1] * e, dp2[i - 1] * e, dp1[i - 1])
//             dp2[i] = min(dp1[i - 1] * e, dp2[i - 1] * e, dp2[i - 1])
//         elif g == '/':
//             dp1[i] = max(dp1[i - 1] / e, dp2[i - 1] / e, dp1[i - 1])
//             dp2[i] = min(dp1[i - 1] / e, dp2[i - 1] / e, dp2[i - 1])
//         else:
//             dp1[i] = max(-1 * dp1[i - 1], -1 * dp2[i - 1], dp1[i - 1])
//             dp2[i] = min(-1 * dp1[i - 1], -1 * dp2[i - 1], dp2[i - 1])

//     return dp1[b]


// def main():
//     t = int(input())
//     for _ in range(t):
//         b = int(input())
//         operations = []
//         for _ in range(b):
//             line = input().split()
//             g = line[0]
//             e = int(line[1]) if len(line) > 1 else 0
//             operations.append((g, e))

//         result = maximize_minimize(b, operations)
//         print(result)


// if __name__ == "__main__":
//     main()
