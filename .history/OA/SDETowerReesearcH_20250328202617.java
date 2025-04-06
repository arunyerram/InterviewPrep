

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
            int cnt = 0;
            int n = arr.size();
            

            
            System.out.println(cnt);
            sc.close();
        }
    }
} 