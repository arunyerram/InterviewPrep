#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    int b[] = {1, 4, -1, 2};
    int target = 4;
    int count = 0;

    // Initialize counters for different cases
    int c1 = 0;  // Count of elements equal to target / 2
    int c2 = 0;  // Count of elements greater than 0 and less than target / 2
    int c3 = 0;  // Count of elements less than 0 and greater than -target / 2
    int c4 = 0;  // Count of elements equal to -target / 2
    int c5 = 0;

    if (target % 2 != 0) {
        std::cout << 0 << std::endl;
    } else {
        int halfTarget = target / 2;

        for (int i = 0; i < n; i++) {
            if (b[i] == halfTarget) {
                c1++;
            } else if (b[i] == -halfTarget) {
                c4++;
            } else if (b[i] >= 0 && b[i] < halfTarget) {
                c2++;
            } else if (b[i] < 0 && b[i] > -halfTarget) {
                c3++;
            }
            
            if(b[i]<0 and abs(b[i])<=halfTarget)
            c5++;
        }

        // Calculate the valid pairs based on the cases
        // Case 1: Positive halfTarget pairs with any smaller positive number
        count += c1 * c2;

        // Case 2: Negative halfTarget pairs with any larger negative number
        count += c4 * c3;
        
        count += c1*c5;

        count += c1 * (c1 - 1) / 2;  // Combinations of (halfTarget, halfTarget)
        count += c4 * (c4 - 1) / 2;  // Combinations of (-halfTarget, -halfTarget)

        std::cout << count << std::endl;
    }

    return 0;
}



public class Main {
    public static void main(String[] args) {
        int n = 4;
        int[] b = {1, 4, -1, 2};
        int target = 4;
        int count = 0;

        // Initialize counters for different cases
        int c1 = 0;  // Count of elements equal to target / 2
        int c2 = 0;  // Count of elements greater than 0 and less than target / 2
        int c3 = 0;  // Count of elements less than 0 and greater than -target / 2
        int c4 = 0;  // Count of elements equal to -target / 2
        int c5 = 0;

        if (target % 2 != 0) {
            System.out.println(0);
        } else {
            int halfTarget = target / 2;

            for (int i = 0; i < n; i++) {
                if (b[i] == halfTarget) {
                    c1++;
                } else if (b[i] == -halfTarget) {
                    c4++;
                } else if (b[i] >= 0 && b[i] < halfTarget) {
                    c2++;
                } else if (b[i] < 0 && b[i] > -halfTarget) {
                    c3++;
                }

                if (b[i] < 0 && Math.abs(b[i]) <= halfTarget) {
                    c5++;
                }
            }

            // Calculate the valid pairs based on the cases
            count += c1 * c2;  // Case 1: Positive halfTarget pairs with any smaller positive number
            count += c4 * c3;  // Case 2: Negative halfTarget pairs with any larger negative number
            count += c1 * c5;
            count += c1 * (c1 - 1) / 2;  // Combinations of (halfTarget, halfTarget)
            count += c4 * (c4 - 1) / 2;  // Combinations of (-halfTarget, -halfTarget)

            System.out.println(count);
        }
    }
}
