// Given two arrays; a and b -> you can start at index 1 from any array and end your journey at index n on an array 

// -> If you are at i you can can jump to i+1 on same array or different array 

// -> -1000000000 <= a[i],b[i]<= 10000000000 

// -> Please output total number of journeys which have even sum and total number of journeys which have odd sum; 

// -> dpa_even_[1] = if number a[1] is even then answer is 1 else 0

// -> dpa_even[2] = considering both array till index “2” and a[2] is forcefully selected when journey ends at index “2”; 

// -> dpb_even[i] = 

// -> dpa_odd[i] = 

// -> dpb_odd[i] = number of journeys ending at b[i] whose sum is odd; 

// -> Total even journeys = dp_a_even[n] + dp_b_even[n] 


// -> if b[i] % 2 == 0 
// -> dpb_even[i] = dpb_even[i-1] + dpa_even[i-1] 
// -> if b[i] % 2 !=0 
// -> dpb_even[i] = dpb_odd[i-1] + dpa_odd[i-1] 

// -> Similarly make the formula for dpa_odd[],dpb_odd,dpa_even[]...

// C++ https://ideone.com/UWpbIY 
// Java. https://ideone.com/TgQJ2C 
// Py https://www.jdoodle.com/ia/1Aup 






#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<ll> dpa_even(n + 1, 0), dpa_odd(n + 1, 0);
    vector<ll> dpb_even(n + 1, 0), dpb_odd(n + 1, 0);

    // Base Cases
    dpa_even[1] = (a[1] % 2 == 0);
    dpa_odd[1] = (a[1] % 2 != 0);
    dpb_even[1] = (b[1] % 2 == 0);
    dpb_odd[1] = (b[1] % 2 != 0);

    for (int i = 2; i <= n; i++) {
        if (a[i] % 2 == 0) {
            dpa_even[i] = dpa_even[i - 1] + dpb_even[i - 1];
            dpa_odd[i] = dpa_odd[i - 1] + dpb_odd[i - 1];
        } else {
            dpa_even[i] = dpa_odd[i - 1] + dpb_odd[i - 1];
            dpa_odd[i] = dpa_even[i - 1] + dpb_even[i - 1];
        }

        if (b[i] % 2 == 0) {
            dpb_even[i] = dpb_even[i - 1] + dpa_even[i - 1];
            dpb_odd[i] = dpb_odd[i - 1] + dpa_odd[i - 1];
        } else {
            dpb_even[i] = dpb_odd[i - 1] + dpa_odd[i - 1];
            dpb_odd[i] = dpb_even[i - 1] + dpa_even[i - 1];
        }
    }

    ll total_even = dpa_even[n] + dpb_even[n];
    ll total_odd = dpa_odd[n] + dpb_odd[n];

    cout << "Even Journeys: " << total_even << endl;
    cout << "Odd Journeys: " << total_odd << endl;

    return 0;
}











// import java.util.*;

// public class Main {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();

//         long[] a = new long[n + 1];
//         long[] b = new long[n + 1];

//         for (int i = 1; i <= n; i++) a[i] = sc.nextLong();
//         for (int i = 1; i <= n; i++) b[i] = sc.nextLong();

//         long[] dpa_even = new long[n + 1], dpa_odd = new long[n + 1];
//         long[] dpb_even = new long[n + 1], dpb_odd = new long[n + 1];

//         dpa_even[1] = (a[1] % 2 == 0) ? 1 : 0;
//         dpa_odd[1] = (a[1] % 2 != 0) ? 1 : 0;
//         dpb_even[1] = (b[1] % 2 == 0) ? 1 : 0;
//         dpb_odd[1] = (b[1] % 2 != 0) ? 1 : 0;

//         for (int i = 2; i <= n; i++) {
//             if (a[i] % 2 == 0) {
//                 dpa_even[i] = dpa_even[i - 1] + dpb_even[i - 1];
//                 dpa_odd[i] = dpa_odd[i - 1] + dpb_odd[i - 1];
//             } else {
//                 dpa_even[i] = dpa_odd[i - 1] + dpb_odd[i - 1];
//                 dpa_odd[i] = dpa_even[i - 1] + dpb_even[i - 1];
//             }

//             if (b[i] % 2 == 0) {
//                 dpb_even[i] = dpb_even[i - 1] + dpa_even[i - 1];
//                 dpb_odd[i] = dpb_odd[i - 1] + dpa_odd[i - 1];
//             } else {
//                 dpb_even[i] = dpb_odd[i - 1] + dpa_odd[i - 1];
//                 dpb_odd[i] = dpb_even[i - 1] + dpa_even[i - 1];
//             }
//         }

//         long total_even = dpa_even[n] + dpb_even[n];
//         long total_odd = dpa_odd[n] + dpb_odd[n];

//         System.out.println("Even Journeys: " + total_even);
//         System.out.println("Odd Journeys: " + total_odd);
//     }
// }






// def count_even_odd_journeys(n, a, b):
//     # Initialize DP arrays
//     dpa_even = [0] * (n + 1)
//     dpb_even = [0] * (n + 1)
//     dpa_odd = [0] * (n + 1)
//     dpb_odd = [0] * (n + 1)

//     # Base case
//     dpa_even[1] = 1 if a[1] % 2 == 0 else 0
//     dpa_odd[1] = 1 if a[1] % 2 != 0 else 0
//     dpb_even[1] = 1 if b[1] % 2 == 0 else 0
//     dpb_odd[1] = 1 if b[1] % 2 != 0 else 0

//     # Fill the DP tables
//     for i in range(2, n + 1):
//         if a[i] % 2 == 0:
//             dpa_even[i] = dpa_even[i - 1] + dpb_even[i - 1]
//             dpa_odd[i] = dpa_odd[i - 1] + dpb_odd[i - 1]
//         else:
//             dpa_even[i] = dpa_odd[i - 1] + dpb_odd[i - 1]
//             dpa_odd[i] = dpa_even[i - 1] + dpb_even[i - 1]

//         if b[i] % 2 == 0:
//             dpb_even[i] = dpb_even[i - 1] + dpa_even[i - 1]
//             dpb_odd[i] = dpb_odd[i - 1] + dpa_odd[i - 1]
//         else:
//             dpb_even[i] = dpb_odd[i - 1] + dpa_odd[i - 1]
//             dpb_odd[i] = dpb_even[i - 1] + dpa_even[i - 1]

//     # Total even and odd journeys
//     total_even = dpa_even[n] + dpb_even[n]
//     total_odd = dpa_odd[n] + dpb_odd[n]

//     return total_even, total_odd


// # Input
// n = int(input("Enter n: "))
// a = [0] + list(map(int, input(f"Enter {n} elements of array a: ").split()))
// b = [0] + list(map(int, input(f"Enter {n} elements of array b: ").split()))

// # Output results
// even_journeys, odd_journeys = count_even_odd_journeys(n, a, b)
// print(f"Total even journeys: {even_journeys}")
// print(f"Total odd journeys: {odd_journeys}")
