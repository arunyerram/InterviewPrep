#include <bits/stdc++.h>
using namespace std;

// vec     : your numbers
// ops     : the three operators you want to try
// chosen  : will collect exactly vec.size()-1 ops along one path
// idx     : how many operators have we chosen so far
// mn      : running minimum across all full expressions
void Recurse(const vector<int>& vec,
             const vector<char>& ops,
             vector<char>& chosen,
             int idx,
             int &mn)
{
    // base: we've picked one op between every adjacent pair
    if (idx == (int)vec.size() - 1) {
        int val = vec[0];
        // apply chosen[0] between vec[0] and vec[1], then chosen[1] between result and vec[2], …
        for (int j = 0; j < (int)chosen.size(); ++j) {
            char op = chosen[j];
            int nxt = vec[j+1];
            if      (op == '+') val = val + nxt;
            else if (op == '-') val = val - nxt;
            else /* op=='*' */  val = val * nxt;
        }
        mn = min(mn, val);
        return;
    }

    // try each operator at position idx
    for (char op : ops) {
        chosen.push_back(op);
        Recurse(vec, ops, chosen, idx+1, mn);
        chosen.pop_back();
    }
}

int main(){
    vector<int> numbers = {12, 23, 3, 1};
    vector<char> ops    = {'-', '*', '+'};

    int mn = INT_MAX;
    vector<char> chosen_ops;
    Recurse(numbers, ops, chosen_ops, 0, mn);

    cout << mn << "\n";  // prints -34
    return 0;
}
