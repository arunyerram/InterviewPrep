#include <bits/stdc++.h>

using namespace std;

int convert(string s){
    
    int u1 = int(s[0]);
    int u5 = int(s[1]);
    
    int v = (u1*10 + u5)*60;
    
    u1 = int(s[3]);
    u5 = int(s[4]);
    
    v = v + (u1*10 + u5);
    
    return v ;
}

void ck(int g){
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
    int n;
    cin>>n;
    
    int k ; 
    cin>>k;
    
    int y[1441] = {0};
    
    for(int i=0;i<n;i++){
        string a,b,v1,v5;
        cin>>a;
        cin>>b; 
        cin>>v1>>v5;
        
        int t1 = convert(v1);
        int t5 = convert(v5);
        //cout<<t1<<" "<<t5;
        //cout<<'\n';
        y[t1] = y[t1] + 1 ; 
        y[t5+1] = y[t5+1] - 1 ; 
    }
    
    
    int i=1;
    while(i<1440){
        
        y[i] = y[i] + y[i-1];
        
        i++;
    }
    
    int c = 0 ; int g = 0 ; 
    for(int i=0;i<1440;i++){
        
        if(y[i]==0){
            c++;
            
            if(c==k)
            {
                ck(i-k+1);//convert this to (hh:mm)
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
    
    
    
}