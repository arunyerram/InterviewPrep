

mport java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
public class MaxOfAllSubarraysOfSizeK
{
private static int[] maxofAllSubarray(int[] a, int k)
{
int n = a.length;
int[] maxOfSubarrays = new int[n-k+1];
int idx = 0;
PriorityQueue<Integer> q = new PriorityQueue<>(Comparator.reverseOrder());
int windowStart = 0;
for(int windowEnd = 0; windowEnd < n; windowEnd++)
{
        q.add(a[windowEnd]);
        if(windowEnd-windowStart+1 == k)
        {
        /* We've hit the window size. Find the maximum in the current
        window and Slide the window ahead*/
        int maxElement = q.peek();
        maxOfSubarrays[idx++] = maxElement;
        if(maxElement == a[windowStart])
        {
        /* Discard a[windowStart] since we are sliding the window
        now. So, it is going out of the window.*/
        q.remove();
        }
        windowStart++; // Slide the window ahead
        }
        }
return maxOfSubarrays;
}
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int[] a = new int[n];
COMPETITIVE PROGRAMMING UNIT-I III –II SEM(KR21)
for(int i = 0; i < n; i++)
{
a[i] = sc.nextInt();
}
int k = sc.nextInt();
int[] result = maxofAllSubarray(a, k);
for(int i = 0; i < result.length; i++)
{
System.out.print(result[i] + " ");
}
}
}