#include<bits/stdc++.h>
using namespace std;

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



    // import java.util.*;

    // class Solution {
    //     public List<String> commonChars(String[] words) {
    //         Map<Character, Integer> mp = new HashMap<>();
            
    //         // Initialize frequency map with a high value
    //         for (char ch = 'a'; ch <= 'z'; ch++) {
    //             mp.put(ch, Integer.MAX_VALUE);
    //         }
            
    //         // Process each word
    //         for (String word : words) {
    //             Map<Character, Integer> m = new HashMap<>();
    //             for (char ch : word.toCharArray()) {
    //                 m.put(ch, m.getOrDefault(ch, 0) + 1);
    //             }
    
    //             for (char ch = 'a'; ch <= 'z'; ch++) {
    //                 mp.put(ch, Math.min(mp.get(ch), m.getOrDefault(ch, 0)));
    //             }
    //         }
            
    //         // Construct the result
    //         List<String> ans = new ArrayList<>();
    //         for (char ch = 'a'; ch <= 'z'; ch++) {
    //             int cnt = mp.get(ch);
    //             while (cnt > 0) {
    //                 ans.add(String.valueOf(ch));
    //                 cnt--;
    //             }
    //         }
            
    //         return ans;
    //     }
    
    //     public static void main(String[] args) {
    //         Solution sol = new Solution();
    //         String[] words = {"bella", "label", "roller"};
    //         System.out.println(sol.commonChars(words));  // Output: ["e", "l", "l"]
    //     }
    // }
    


