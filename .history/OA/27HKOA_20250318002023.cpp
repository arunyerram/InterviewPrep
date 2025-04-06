#include <bits/stdc++.h>
using namespace std;

int convert(string s){
    //this convert time string to integer
    //00:12 ----> converted to ---> 12.
    //01:01-----> converted to ---> 61.
    int u1 = int(s[0])-48;
    int u5 = int(s[1])-48;
 
    int v = (u1*10 + u5)*60;
 
    u1 = int(s[3])-48;
    u5 = int(s[4])-48;
 
    v = v + (u1*10 + u5);
 
    return v 
    ;
}
 
void convert_integer_totimestring(int g){
	int u = g/60;
	int y = g%60;
 
	if(u<=9){
		cout<<"0";
		cout<<u;
	}
	else{
		cout<<u;
	}
	cout<<":";
 
 
	if(y<=9){
		cout<<"0";
		cout<<y;
	}
	else{
		cout<<y;
	}
}



int main() {
    int n, k;
    cin >> n >> k;

    // Initialize array b with zeros
    vector<int> y(1440, 0);

    string start,end,a,b;
    // assuming these inputs are given
    

    // O(N^2) loop
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        cin >> start >> end;
        
        int t1 = convert(start);
        int t5 = convert(end);

        // O(N) loop
        for (int l = t1; l <= t5; l++) {
            y[l] = y[l] + 1;
        }
    }

   int c = 0 ; int g = 0 ; 
    for(int i=0;i<1440;i++){
 
        if(y[i]==0){
            c++;
 
            if(c==k)
            {
                convert_integer_totimestring(i-k+1);//convert this to (hh:mm)
                g = 1 ; 
                break ; 
            }
 
        }
        else{
            c = 0 ; 
        }
 
    }
 
    if(g==0){
        cout<<"-1";
    }
 

    return 0;
}
