// -> Given an array of size “N”; find -> find the number of unordered quadruplets (i,j,k,l) such that b[i] + b[j] + b[k] + b[l] = 0 

// -> [1 2 3 4 -1 -2 -2] 

// -> 3 [1,2,5,6]  [1,2,5,7] [1,3,6,7] 


//  cpp code:

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt = 0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                for(int l=k+1;l<=n;l++)
                    if((a[i]+a[j]+a[k]+a[l]) == 0) cnt++;    //....... O(n^4) TC,  O(1) SC....../////////////////
    
    cout<<cnt<<endl;
    int tot = 0;
    map<int,int>mp;
    for(int i=4;i<=n;i++) mp[a[i]]++;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) {
            for(int k=j+1;k<=n;k++){
                    int sum = 0 - a[i] - a[j] - a[k];
                    if(mp.find(sum) != mp.end())
                        tot += mp[sum];
                    
                    mp[a[k + 1]]++;
                }
                for(int k=j+3;k<=n;k++){
                    mp[a[k]]++;
                }  ///////////// O(n^3) TC, O(n) SC..........................
            }
        }
    cout<<tot<<endl;      ////////////////////////// O(n^3) TC, O(n) SC/.................................


    cnt = 0;
    map<int,int>mp1;       //mapping sum with its frequency
    for(int i=3;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum = a[i] + a[j];
            mp1[sum]++;
        }
    }

    for(int i=1;i<=n-2;i++){
        for(int j=1;j<i;j++){
            int sum = 0 - a[i] - a[j];
            if(mp1.find(sum) != mp1.end())
                cnt += mp1[sum];
        }  // ////////////////////optimal ..........................
        
    }cout<<cnt<<endl;  ///////////.............// O(n^2) TC, O(n^2) SC.............................
    return 0;
}




// java code:

// import java.util.*;
// import java.lang.*;
// import java.io.*;

// public class Main {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int[] arr = new int[n];
//         for (int i = 0; i < n; i++) {
//             arr[i] = sc.nextInt();
//         }
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     for (int l = k + 1; l < n; l++) {
//                         if (arr[i] + arr[j] + arr[k] + arr[l] == 0) {
//                             cnt++;
//                         }
//                     }
//                 }
//             }
//         }
//         System.out.println(cnt);

//         // O(n^4) TC, O(1) SC
//         // }

//     public static int findCount(int[] arr, int n) {
//         int cnt = 0;

//         Map<Integer, Integer> map = new HashMap<>();
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int sum = arr[i] + arr[j];
//                 map.put(sum, map.getOrDefault(sum, 0) + 1);
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int sum = -(arr[i] + arr[j]);
//                 cnt += map.getOrDefault(sum, 0);
//             }
//         }

//         return cnt; 
//     }  // O(n^2) TC, O(n^2) SC

//     public static int findCount(int[] arr, int n) {
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     int sum = -(arr[i] + arr[j] + arr[k]);
//                     cnt += map.getOrDefault(sum, 0);
//                 }
//             }
//         }
//         return cnt;
// } 
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int[] arr = new int[n];
//         for (int i = 0; i < n; i++) {
//             arr[i] = sc.nextInt();
//         }
//         int cnt = findCount(arr, n);
//         System.out.println(cnt);
//         }
//     }

//      // O(n^3) TC, O(n) SC
// //      

