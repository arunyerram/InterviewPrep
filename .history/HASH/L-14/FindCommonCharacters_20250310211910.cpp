class Solution {
    public:
        vector<string> commonChars(vector<string>& words) {
            map<char,int>mp;
            for(char ch='a';ch <= 'z';ch++){
                mp[ch] = 10000;
            }
            for(auto it:words){
                map<char,int>m;
                for(auto i:it){
                    m[i]++;
                }
    
                for(char ch = 'a';ch<='z';ch++){
                    mp[ch] = min(mp[ch],m[ch]);
                }
            }
            vector<string>ans;
            for(auto it:mp){
                int cnt = it.second;
                while(cnt > 0){
                    ans.push_back(string(1,it.first));
                    cnt--;
                }
            }
            return ans;
        }
    };