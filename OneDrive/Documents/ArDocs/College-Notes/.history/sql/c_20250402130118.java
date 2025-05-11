package sql;
import java.util.*;
public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = n + 1;

        String ans="";
        while(m>0){
            if(m%2==0){
                ans += "0";
            }else{
                ans += "1";
            }
            m /= 2;
        }
        // Collections.reverse(ans);
        int i = 0,j=ans.length()-1;
        String t="";
        while(j>=0){
            t += ans.charAt(j);
            j--;
        }
        while(i<n && t.charAt(i) == '0'){
            i++;
        }

    }
}
