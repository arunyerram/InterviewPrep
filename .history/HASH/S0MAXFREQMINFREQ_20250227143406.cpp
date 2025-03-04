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





//  -------JAVA  ------------


// import java.util.HashMap;
// import java.util.Map;

// public class Main {
//     public static void main(String[] args) {
//         int n = 6;
//         int[] arr = {1, 1, 2, 3, 3, 3};

//         Map<Integer, Integer> mp = new HashMap<>();
//         int maxiFreq = Integer.MIN_VALUE, maxiElement = arr[0];
//         int miniFreq = Integer.MAX_VALUE, miniElement = arr[0];

//         for (int i = 0; i < arr.length; i++) {
//             mp.put(arr[i], mp.getOrDefault(arr[i], 0) + 1);
//         }
        
//         for (Map.Entry<Integer, Integer> num : mp.entrySet()){
//             if (num.getValue() >= maxiFreq){
//                 maxiFreq = num.getValue();
//                 maxiElement = num.getKey();
//             }
//             if (num.getValue() <= miniFreq){
//                 miniFreq = num.getValue();
//                 miniElement = num.getKey();
//             }
//         }

        

//         System.out.println("Max frequency element: " + maxiElement + " with frequency: " + maxiFreq);
//         System.out.println("Min frequency element: " + miniElement + " with frequency: " + miniFreq);
//     }
// }




// --------- PYTHON ------

