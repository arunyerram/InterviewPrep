#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    map<int, int> mp;
    
    int maxiFreq = 0, maxiElement = 0;
    int miniFreq = n+1, miniElement = 0;
    
    for(int i = 0; i < n; i++) {
      
        mp[arr[i]]++;
        
    }
    
    for(auto i : mp){
        
        int element = i.first, freq = i.second;
        
        if(freq < miniFreq){
            miniFreq = freq;
            miniElement = element;
        }
        
        if(freq > maxiFreq){
            maxiFreq = freq;
            maxiElement = element;
        }
        
    }
    
    cout << "Maximum Frequency: ";
    

    cout << "Frequency: " << maxiFreq << " Element: " << maxiElement << endl;
    
    cout << "Minimum Frequency: ";
    
    cout << "Frequency: " << miniFreq << " Element: " << miniElement << endl;
    
    return 0;
}
