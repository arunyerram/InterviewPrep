#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n + 1);
    for(int i=1;i<=n;i++)cin>>b[i];
    int k;
    cin >> k;
    
    int u = INT_MAX;
    unordered_map<int, int> k_map;
    
    for (int j = 1; j <= n; j++) {
    	
    	int end = b[j];
        
        int start = k - end;
        
        if(k_map.count(start)){
        	
        	int i = k_map[start];
        
	        int l = j - i + 1;
	        u = min(u, l);
	        
	        }
        
        k_map[end] = j;
    }
    
    cout << u << endl;
    
    return 0;
}
