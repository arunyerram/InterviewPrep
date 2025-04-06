import java.util.Scanner;
import java.util.TreeMap;
import java.util.*;

public class 26RubrikSDE{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Size of the array
        int x = scanner.nextInt();  // First integer
        int y = scanner.nextInt();  // Second integer
        int z = scanner.nextInt();  // Third integer
        int w = scanner.nextInt();  // Fourth integer
        int b = scanner.nextInt();  // Fifth integer

        int[] arr = new int[n + 1];  // Array of size n + 1

        // Input the array
        for (int i = 1; i <= n; i++) {
            arr[i] = scanner.nextInt();
        }

        long count = 0;  // Count of valid subarrays
        TreeMap<Key, Integer> freq = new TreeMap<>((a, b1) -> {
            if (a.d1 != b1.d1) return Integer.compare(a.d1, b1.d1);
            if (a.d2 != b1.d2) return Integer.compare(a.d2, b1.d2);
            if (a.d3 != b1.d3) return Integer.compare(a.d3, b1.d3);
            return Integer.compare(a.d4, b1.d4);
        });  // TreeMap to store frequencies of pairs
        
        freq.put(new Key(0, 0, 0, 0), 1);  // Base case: (d1, d2, d3, d4) has been achieved once

        int cx = 0, cy = 0, cz = 0, cw = 0, cb = 0;  // Counters for x, y, z, w, b

        // Loop through the array
        for (int i = 1; i <= n; i++) {
            // Update counters based on the value of arr[i]
            if (arr[i] == x) {
                cx++;
            } else if (arr[i] == y) {
                cy++;
            } else if (arr[i] == z) {
                cz++;
            } else if (arr[i] == w) {
                cw++;
            } else if (arr[i] == b) {
                cb++;
            }

            // Compute differences
            int d1 = cy - cx;  // First condition difference
            int d2 = cz - cy;  // Second condition difference
            int d3 = cw - cz;  // Third condition difference
            int d4 = cb - cw;  // Fourth condition difference

            Key key = new Key(d1, d2, d3, d4);
            count += freq.getOrDefault(key, 0);  // Increment count based on how many times (d1, d2, d3, d4) was achieved
            
            // Update frequency of (d1, d2, d3, d4)
            freq.put(key, freq.getOrDefault(key, 0) + 1);  
        }

        System.out.println(count);  // Output the count
        scanner.close();
    }
}

class Key {
    int d1;
    int d2;
    int d3;
    int d4;

    public Key(int d1, int d2, int d3, int d4) {
        this.d1 = d1;
        this.d2 = d2;
        this.d3 = d3;
        this.d4 = d4;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(d1) * 31 * 31 * 31 + Integer.hashCode(d2) * 31 * 31 + Integer.hashCode(d3) * 31 + Integer.hashCode(d4);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Key key = (Key) obj;
        return d1 == key.d1 && d2 == key.d2 && d3 == key.d3 && d4 == key.d4;
    }
}
