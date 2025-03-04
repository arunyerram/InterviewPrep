#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n; 
    cin>>n ; 
    vector <int> b ; 
    int i = 0 ; 
    while(i<n){
        int yy ; cin>>yy ; 
        b.push_back(yy);
        i++;
    }
    sort(b.begin(),b.end()); 
    
    auto mg = upper_bound(b.begin(),b.end(),35); 
    auto kf = mg - b.begin();
    
    int ram=kf;//returns__the index of number slightly greater than 100 in array/.

		  //cout<<ram<<"\n";
	int lol = b[ram] ;
	cout<<ram ; 
	cout<<'\n';
    cout<<lol; 
    
    return 0 ; 
}





public class Main {
    public static int upperBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 6 , 6, 7, 7, 9};
        int target = 6;
        int upperBoundIndex = upperBound(arr, target);

        if (upperBoundIndex < arr.length) {
            System.out.println("Upper bound of " + target + " is at index " + upperBoundIndex);
        } else {
            System.out.println("Upper bound of " + target + " is not found in the array. n = " + arr.length);
        }
    }
}
public class Main {
    public static int upperBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 6 , 6, 7, 7, 9};
        int target = 6;
        int upperBoundIndex = upperBound(arr, target);

        if (upperBoundIndex < arr.length) {
            System.out.println("Upper bound of " + target + " is at index " + upperBoundIndex);
        } else {
            System.out.println("Upper bound of " + target + " is not found in the array. n = " + arr.length);
        }
    }
}
