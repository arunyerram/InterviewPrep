
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://www.linkedin.com/posts/kumark1_ramram-kumark-job-activity-7342907708230049792-54Hw?utm_source=share&utm_medium=member_desktop&rcm=ACoAADB1e44BA43UYjFx2BwtGFrtyTJFuENef5c (like it to get referral) 
// 
// -> https://training.desiqna.in 
// 
// Link :-> https://www.desiqna.in/18805/juspay-oa-2025-grid-irrigation-management-kumar-k 
// 
// Understanding :-> You are given “N” taps; Initially all taps are available; each tag provide c[i] litres of water when used; you have to reach total ‘G’ litres of water or more than ‘G’ -> once a particular tap gets used at time t = u ; then this tap can be used again only at time t = u + r[i] 
// 
// Analysis :-> We should use all the taps on Day 1 only => why is this is optimal :-> 
// 
// Greedy proof by contradiction; explained in vid;  
// 
// Brute force :-> Just simulate the whole process; 
// 
// Optimization :-> If it is asked to you :-> How much water can you get in the best way in 5 seconds? 
// 
// 
// :->  tn = a + (n-1)*d; 
// 
// :-> for the tap-”i” :-> q_i = (5-a)/d + 1 = (5-1)/r[i] + 1 -> O(1);
// 
// -> q_i => how many times the tap “i” can be used in the first “5” seconds; 
// 
// -> total water :-> q_1*c[1] + q_2*c[2] + …….. q_n*c[n] :-> O(N); 
// 
// Basic solution :-> 
// 
// If total water you get at T==1 is >=G answer is 1 
// 
// Else you will try for T==2; 
// 
// Else you will try for T==3; 
// .
// .
// .
// .
// .
// 
// At T==6; you capacity becomes >=G then 6 is the ans; 
// C++ - https://www.jdoodle.com/ia/1IcK 
// Java - https://www.jdoodle.com/ia/1IcM 
// Py - https://ideone.com/ln7pat 
// 
// Binary Search for “T” :-> low = 1 Max = 10^9 ; 
// 
// O(N*logT) 
// 
// Monotonic increasing function :-> 
// 
// “FFFFFFFFFFFFTTTTTTTTTTTTTTTTTTTTT…….” 
// 
// Takes O(1) size; space; 
// 
// C++ - https://www.jdoodle.com/ia/1IcR 
// Java - https://www.jdoodle.com/ia/1IcW 
// Py - https://ideone.com/SoJSEa 
// 
// 
// 

// .............BS..................
ll N;
ll func(ll mid, ll c[], ll r[]){
    ll sum = 0;
    for(int j=1;j<N;j++){
        sum = sum + c[j]*(((mid-1)/r[j]) + 1); 
    }
    return sum;
}

int main(){
    ll g;cin>>g;
    ll n;cin>>n;
    N = n;
    ll c[n + 1] = {0};
    ll r[n + 1] = {0};

    for(int i=1;i<n;i++){
        cin>>c[i];
    }
    ll mx = -1;
    for(int j = 1;j<n;j++){
        cin>>r[j];
        mx = max(mx, r[j]);
    }
    ll low = 1;ll lst = 1e18;
    while(low <= lst){
        ll mid = (low + lst) / 2;
        if(func(mid,c,r) >= g){
            mx = mid;
            lst = mid-1;
        }else low = mid + 1; 
    }
    cout<<mx<<endl;
    return 0;
}


// import java.util.*;

// public class Main {
//     static long n;

//     static long cl(long i, long[] c, long[] r) {
//         long sum = 0;
//         for (int j = 1; j <= n; j++) {
//             sum += c[j] * ((i - 1) / r[j] + 1);
//         }
//         return sum;
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         long G = sc.nextLong();
//         n = sc.nextLong();

//         long[] c = new long[(int) n + 1];
//         long[] r = new long[(int) n + 1];

//         for (int i = 1; i <= n; i++) {
//             c[i] = sc.nextLong();
//         }

//         for (int i = 1; i <= n; i++) {
//             r[i] = sc.nextLong();
//         }

//         long low = 1;
//         long high = (long) 1e18;
//         long answer = -1;

//         while (low <= high) {
//             long mid = (low + high) / 2;
//             if (cl(mid, c, r) >= G) {
//                 answer = mid;
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }

//         System.out.println(answer);
//     }
// }
