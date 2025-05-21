/*
 given an array of int, u are initially positioned at the 1st index at the array
    in one step you can jump from index i to index:
    -> i+1 where i+1 < arr.length;
    -> i-1 where i-1 >= 0
    -> j where: arr[i] == arr[j] and i!=j
    find the minimum number of steps to reach the last index
   Notice that you can not jump outside of the array at any time.
 
 */

import java.util.*;

public class MinimumSteps {
    public int minJumps(int[] arr) {
        if (arr == null || arr.length == 0) return -1;
        if (arr.length == 1) return 0;

        int n = arr.length;
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.computeIfAbsent(arr[i], x -> new ArrayList<>()).add(i);
        }

        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        queue.offer(0);
        visited[0] = true;
        int steps = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int index = queue.poll();
                if (index == n - 1) return steps;

                List<Integer> nextIndices = graph.get(arr[index]);
                nextIndices.add(index - 1);
                nextIndices.add(index + 1);

                for (int nextIndex : nextIndices) {
                    if (nextIndex >= 0 && nextIndex < n && !visited[nextIndex]) {
                        visited[nextIndex] = true;
                        queue.offer(nextIndex);
                    }
                }
                nextIndices.clear(); // Clear the list to prevent redundant processing
            }
            steps++;
        }
        return -1;
    }

    public static void main(String[] args) {
        MinimumSteps solution = new MinimumSteps();
        int[] arr = {100, 23, 100, 100, 23, 100, 100, 100, 100, 100};
        System.out.println(solution.minJumps(arr)); // Output the minimum number of steps
    }
}