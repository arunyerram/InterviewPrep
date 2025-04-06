

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
            // list.sort(Map.Entry.comparingByValue(Collections.reverseOrder()));

            int n = arr.size();
            Long cnt = 0L;
            for (int bit = 0; bit < 32; bit++) {  
                ArrayList<Integer> binaryArray = new ArrayList<>();
                for (int num : arr) {
                    binaryArray.add((num >> bit) & 1);
                }

                Long c0 = 0L, c1 = 0L, sum = 0L;
                for (int i = 0; i < binaryArray.size(); i++) {
                    if (binaryArray.get(i) == 0) {
                        c0 = c0 + 1;
                    } else {
                        Long c2 = c0;
                        c0 = c1;
                        c1 = c2 + 1;
                    }
                    sum += c1;
                }
                cnt += sum * (1L << bit);
            }
            System.out.println(cnt);
            sc.close();
        }
    }
} 