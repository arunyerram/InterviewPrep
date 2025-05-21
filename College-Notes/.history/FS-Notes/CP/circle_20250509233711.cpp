


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isCircle(vector<string>& words, int index, vector<string>& result) {
    if (index == words.size()) {
        // Check if the last word connects to the first
        if (words.back().back() == words.front().front()) {
            result = words;  // ✅ Store the successful order
            return true;
        }
        return false;
    }

    for (int i = index; i < words.size(); i++) {
        if (index == 0 || words[index - 1].back() == words[i].front()) {
            swap(words[index], words[i]);
            if (isCircle(words, index + 1, result)) return true;
            swap(words[index], words[i]); // backtrack
        }
    }

    return false;
}

int main() {
    vector<string> words = {"abc", "cde", "eab"};
    vector<string> result;

    if (isCircle(words, 0, result)) {
        cout << "Can form a circle\nOrder: ";
        for (const string& word : result) {
            cout << word << " ";
        }
        cout << endl;
    } else {
        cout << "Cannot form a circle" << endl;
    }

    return 0;
}