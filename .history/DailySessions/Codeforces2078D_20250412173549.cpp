#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin >> n;
        cin.ignore(); 

        vector<vector<string>> matrix(n, vector<string>(4));

        for (int i = 0; i < n; ++i) {
            // string token;
            for (int j = 0; j < 4; ++j) {
                cin >> matrix[i][j];
            }
        }
        ll l = 1;
        ll r = 1;

        for(int i = 0; i < n; ++i) {
            string c1 = matrix[i][0];
            string c2 =  matrix[i][2];
            int num1 = stoi(matrix[i][1]);
            int num2 = stoi(matrix[i][3]);
            cout<<num1<<" "<<num2<<endl;

            int tot = 0;
            if(c1 == "+" && c2 == "+") {
                tot = num1 + num2;
            }else if(c1 == "+" && c2 == "*") {
                tot = num1;
                tot += (r*num2 - r);
            }
            else if(c1 == "*" && c2 == "+") {
                tot = num2;
                tot += (l*num1 - l);
            }
            else if(c1 == "*" && c2 == "*") {
                tot = (l*num1 - l)  + (r*num2 - r);
            }
            cout<<"tot: "<<tot<<endl;

            
            if(c1 == "+" && c2 == "+") {
                if(tot%2 == 0){
                    l += tot/2;
                    r += tot/2;
                }else{
                    r += tot/2 + 1;
                    l += tot/2;
                }
                cout<<"l: "<<l<<" r: "<<r<<endl;
            }
            else if(c1 == "+" && c2 == "*") {
                if((l + tot) >= (r + tot)){
                    l += (tot);
                    r += 0;
                }else{
                    l += 0;
                    r += (tot);
                }
                cout<<"l: "<<l<<" r: "<<r<<endl;
            }
            else if(c1 == "*" && c2 == "+") {
                if((l + tot) >= (r + tot)){
                    l += 0;
                    r += (tot);
                }else{
                    l += (tot);
                    r += 0;
                }
                cout<<"l: "<<l<<" r: "<<r<<endl;
            }
            else if(c1 == "*" && c2 == "*") {
                if(num1 >= num2){
                    if(l  + tot >= r + tot){
                        l += (tot);
                        r += 0;
                    }else{
                        l += 0;
                        r += (tot);
                    }
                }else{
                    if(l  + tot >= r + tot){
                        l += 0;
                        r += (tot);
                    }else{
                        l += (tot);
                        r += 0;
                    }
                }
            }
                cout<<"l: "<<l<<" r: "<<r<<endl;
            }
        cout<<(l + r)<<endl;
    }
    return 0;
}















void initpow(int x)
{
    power.resize(NUM);
    power[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        power[i] = (power[i - 1] * (x % mod)) % mod;
    }
}
void initFactorial()
{
    fact.resize(NUM);
    fact[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}



void calc_sieve()
{
    sieve.resize(NUM + 1, 0);
    for (int x = 2; x <= NUM; x++)
    {
        if (sieve[x])
            continue;
        for (int u = x; u <= NUM; u += x)
        {
            sieve[u] = x;
        }
    }
}
void primefactor()
{
    lp.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
int binpow(int a, int b)
{    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int binpow(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return ((a / gcd(a, b)) * b);
}
int inversemod(int a, int mod)
{
    return binpow(a, mod - 2, mod);


}
int divmod(int a, int b, int c)
{
    return ((a % c) * inversemod(b, c)) % c;
}


int combination(int n, int k)
{
    if (k > n)
        return 0;
    int p1 = (fact[n] * inversemod(fact[k], mod)) % mod;
    int p2 = (1 * inversemod(fact[n - k], mod)) % mod;
    return (p1 * p2) % mod;
}