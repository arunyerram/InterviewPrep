// -8 4 6 2 -4

// https://docs.google.com/document/d/1kBBhraTmmds4ntp3qr7DXcDETn0YGSSIrrpz5nmIN4E/edit?tab=t.0



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2,n3,n4,n5;
    cin >> n1,n2,n3,n4,n5;
    vector<int>a,b,c,d,e;

    for(int i=0;i<n1;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<n2;i++){
        int x;
        cin >> x;
        b.push_back(x); 
    }
    for(int i=0;i<n3;i++){
        int x;
        cin >> x;
        c.push_back(x);
    }
    for(int i=0;i<n4;i++){
        int x;
        cin >> x;
        d.push_back(x);
    }
    for(int i=0;i<n5;i++){
        int x;
        cin >> x;
        e.push_back(x);
    }

    map<int,int>mp1;
    map<int,int>mp2;

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            for(int k=0;k<n3;k++){
                mp1[(a[i]+b[j]+c[k])]++;    
            }
        }
    }

    for(int i=0;i<n4;i++){
        for(int j=0;j<n5;j++){
            mp2[(d[i]+e[j])]++;    
        }
    }

    int cnt = 0;
    for(auto it:mp1){
        int ele = it.first;
        if(mp2.find(-1*ele) != mp2.end()){
            cnt += mp1[ele]*mp2[-1*ele];
        }
    }
    cout<<cnt<<endl;
    return 0;
}





// or.........................



#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n = 2; // Assuming n is 2 as per provided arrays
    int a[] = {2, 5};
    int b[] = {3, 8};
    int c[] = {-5, 8};
    int d[] = {5, 10};
    int e[] = {-10, 100};

    unordered_map<int, int> hashmap;

    for (int l = 0; l < n; l++) {
        for (int m = 0; m < n; m++) {
            int sum = d[l] + e[m];
            hashmap[sum]++;
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int required_sum = -(a[i] + b[j] + c[k]);
                count += hashmap[required_sum];
            }
        }
    }

    cout << count << endl;

    return 0;
}
