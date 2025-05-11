/*
 * 
 * Flexible sliding window
 * Find the max number of books we can read in x minutes.
 * Where each element of the array represents the time in minutes required to read a book.
 * 
 * Example
 * For the input array {1, 1, 2, 1, 1, 1, 4, 2} and k = 8;
 * 
 * The algorithm dynamically adjusts the window size to find the maximum number of books that can be read in 8 minutes.
 * It identifies subarrays like {1, 1, 2, 1, 1, 1} and {1, 2, 1, 1, 1} etc., which statisfy the sum condition.
 * the longer subarray has lenght of 6 i.e {1, 1, 2, 1, 1, 1} .length is returned as the output.
 */


 //brute force approach
class NavieMaxBook{
    public static int maxBooks(int[] arr, int k){
        int n = arr.length;
        int max = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                if(sum <= k){
                    max = Math.max(max, j - i + 1);
                }else{
                    break;
                }
            }
        }
        return max;
    }
    public static void main(String[] args) {
        int[] arr = {1, 1, 2, 1, 1, 1, 4, 2};
        int k = 8; // 8 minutes to read
        System.out.println(maxBooks(arr, k));
    }
}


//sliding window approach
public class Books {

    public static int maxBooks(int[] arr, int k){
        int n = arr.length;
        int max = 0;
        int sum = 0;
        int left = 0;
        for(int right = 0; right < n; right++){
            sum += arr[right]; //Expand window by adding right book

            //if sum exceeds k, shrink the window from the left
            while(sum > k){
                sum -= arr[left];
                left++;
            }

            //update max with current window size
            max = Math.max(max, right - left + 1);
            System.out.println("left: " + left + " right: " + right + " sum: " + sum + " max: " + max);
        }
        return max;
    }

    public static void main(String[] args) {
        int[] arr = {1, 1, 2, 1, 1, 1, 4, 2};
        int k = 8; // 8 minutes to read
        System.out.println(maxBooks(arr, k));
    }
}
