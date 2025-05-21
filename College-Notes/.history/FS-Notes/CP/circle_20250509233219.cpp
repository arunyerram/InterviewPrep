



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isCircle(vector<string>& words, int index, vector<string>& result) {
    if (index == words.size()) {
        // Check last and first
        return words.back().back() == words.front().front();
    }

    for (int i = index; i < words.size(); i++) {
        if (index == 0 || words[index - 1].back() == words[i].front()) {
            swap(words[index], words[i]);
            if (isCircle(words, index + 1, result)) {
                if (index == 0) result = words;
                return true;
            }
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
        for (string& w : result) cout << w << " ";
        cout << endl;
    } else {
        cout << "Cannot form a circle" << endl;
    }

    return 0;
}