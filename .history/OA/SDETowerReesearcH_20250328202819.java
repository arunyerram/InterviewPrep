

import java.util.*;
public class SDETowerReesearcH{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()){
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            ArrayList<Integer>arr = new ArrayList<>();

            for(String part:parts){
                arr.add(Integer.parseInt(part));
            }
            // int cnt = 0;
            int n = arr.size();
            Long cnt = 0;
            for (int bit = 0; bit < 32; bit++) {  // Assume 32-bit integers
                ArrayList<int> binaryArray;
                for (int num : b) {
                    binaryArray.push_back((num >> bit) & 1);
                }

                ll c0 = 0, c1 = 0, sum = 0;
                for (int i = 0; i < binaryArray.size(); i++) {
                    if (binaryArray[i] == 0) {
                        c0 = c0 + 1;
                    } else {
                        swap(c0, c1);
                        c1 = c1 + 1;
                    }
                    sum += c1;
                }
                cnt += sum * (1*Long << bit);
            }
            System.out.println(cnt);
            sc.close();
        }
    }
} 