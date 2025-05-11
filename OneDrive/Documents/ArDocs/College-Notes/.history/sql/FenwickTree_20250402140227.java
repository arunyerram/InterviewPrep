package sql;
import java.util.*;
public class FenwickTree {
     int[] nums;
     int[] BIT;
    tatic int n;

    FenwickTree(int[] nums){
        this.nums = nums;
        n = nums.length;
        BIT = new int[n + 1];
        
        for(int i=0;i<n;i++){
            init(i,nums[i]);
        }
    }

    public void init(int i,int val){
        i += 1;
        while(i <= n){
            BIT[i] += val;
            i += (i & (-i));
        }  
    }

    public void update(int i,int val){
        int diff = val - nums[i];
        nums[i] = val;
        init(i,diff);
    }
    public int getSum(int i){
        i += 1;
        int sum = 0;
        while(i > 0){
            sum += BIT[i];
            i -= (i & (-i));
        }
        return sum;
    }

    public int getSumRange(int i,int j){
        return getSum(j) - getSum(i - 1);
    }

    public static void main(String[] args){
        int n,k;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        int[] ar = new int[n];
        for(int i=0;i<n;i++){
            ar[i] = sc.nextInt();
        }
        FenwickTree ft = new FenwickTree(ar);
        while(k-- > 0){
            int a,b,c;
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();

            if(a == 1){
                System.out.println(ft.getSumRange(b,c));
            }else{
                ft.update(b,c);
            }
        }
        sc.close(); 
    }
}
