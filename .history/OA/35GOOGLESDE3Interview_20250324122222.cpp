#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int b[n + 1];
    int pref[n + 1] = {0};
    int suf[n + 1] = {0};
    pref[1] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int j = 2;
    while (j <= n) {
        int c = 0;
        int i = 1;
        while (i <= j - 1) {
            if (b[i] > b[j]) {
                c++;
            }
            i++;
        }
        pref[j] = c;
        j++;
    }

    suf[n] = 0;

    j = n - 1;
    while (j >= 1) {
        int c = 0;
        int k = j + 1;
        while (k <= n) {
            if (b[j] < b[k]) {
                c++;
            }
            k++;
        }
        suf[j] = c;
        j--;
    }

    int c = 0;
    j = 1;
    while (j <= n) {
        c = c + pref[j] * suf[j];
        j++;
    }

    cout << c << endl;

    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int b[n + 1];
    int pref[n + 1] = {0};
    int suf[n + 1] = {0};
    pref[1] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int j = 2;
    while (j <= n) {
        int c = 0;
        int i = 1;
        while (i <= j - 1) {
            if (b[i] > b[j]) {
                c++;
            }
            i++;
        }
        pref[j] = c;
        j++;
    }

    suf[n] = 0;

    int k = n - 1;
    while (k >= 1) {
        int c = 0;
        int l = k + 1;
        while (l <= n) {
            if (b[k] > b[l]) {
                c++;
            }
            l++;
        }
        suf[k] = c;
        k--;
    }

    int c = 0;
    j = 1;

    while (j <= n) {
        int k = j + 1;
        while (k <= n) {
            if (b[j] < b[k]) {
                c = c + pref[j] * suf[k];
            }
            k++;
        }
        j++;
    }

    cout << c ;

    return 0;
}
