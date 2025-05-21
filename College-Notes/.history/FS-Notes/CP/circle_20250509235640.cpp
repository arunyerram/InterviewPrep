#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFormCircle(vector<string>& words, vector<bool>& used, vector<string>& path, int depth) {
        if (depth == words.size()) {
            // Check circular condition: last word's end == first word's start
            return path.back().back() == path[0][0];
        }

        for (int i = 0; i < words.size(); ++i) {
            if (!used[i]) {
                // If it's the first word or it connects to the previous word
                if (depth == 0 || path.back().back() == words[i][0]) {
                    used[i] = true;
                    path.push_back(words[i]);

                    if (canFormCircle(words, used, path, depth + 1)) {
                        return true;
                    }

                    // Backtrack
                    used[i] = false;
                    path.pop_back();
                }
            }
        }
        return false;
    }

    bool checkArrangement(vector<string> words) {
        int n = words.size();
        vector<bool> used(n, false);
        vector<string> path;

        for (int i = 0; i < n; ++i) {
            used[i] = true;
            path.push_back(words[i]);

            if (canFormCircle(words, used, path, 1)) {
                // Valid order found
                cout << "Valid order:\n";
                for (const string& word : path)
                    cout << word << " -> ";
                cout << path[0] << " (back to start)" << endl;
                return true;
            }

            used[i] = false;
            path.pop_back();
        }

        return false;
    }
};
