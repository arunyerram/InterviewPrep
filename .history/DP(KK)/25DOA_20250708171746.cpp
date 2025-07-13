

// There are N tasks. To be performed on N days; each day you perform a single task 

// Each day you have three choices; either perform the easy[i] , medium [i] , hard[i] 

// For doing each task you get some points. 

// Maximize the total points. 

// On day “i” you can do a hard task if and only if the day before the previous day you did an easy task 

// On day “i” you can do a medium task if and only if the day before you did easy task and the day before that you did medium task 

// Applicable from day>2. 



// Solution :- 

// dp_easy[i] = the maximum score you can get if you are doing an easy task on day “i” 


// dp-easy[i] = easy[i]+(max(dp_easy(i-1),dp_medium(i-1),dp_hard(i-1)) 

// dp_medium[i] = the maximum score you can get if you are doing an medium task on day “i” and follow all the conditions required to do medium task on day “i” 

// dp_medium[i]=medium[i]+easy[i-1]+dp_medium[i-2] //RRRRR


// dp_hard[i] = hard[i] + easy[i-1] + dp_easy[i-2] ……

// dp_hard[i] = hard[i] + medium[i-1] + easy[i-2] + dp_medium[I-3]......

// dp_hard[i] = hard[i] + hard[i-1] + easy[i-2] + dp_easy[i-3]........


// Max of all of them is the answer 


// Final answer :- max(dp_easy[n],dp_medium[n],dp_hard[n]) 




// C++ - https://ideone.com/TMizpx. 
// Java - https://ideone.com/JaJ9h4. 
// Py - https://ideone.com/7whQNg 



// https://drive.google.com/file/d/1YsPveaYE0vorHZa_O4aqlSVtAU-9c5iK/view
// https://drive.google.com/file/d/1iq5fhDddKO_3VUodDFNc44-10aY5HYiF/view


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Function to calculate the maximum points
int maximizePoints(int N, const vector<int>& easy, const vector<int>& medium, const vector<int>& hard) {
    if (N == 0) return 0;
 
    vector<int> dp_easy(N + 1, 0);
    vector<int> dp_medium(N + 1, 0);
    vector<int> dp_hard(N + 1, 0);
    
    //starting first few index  - No rule. 
    dp_easy[1] = easy[1];
    dp_medium[1] = medium[1];
    dp_hard[1] = hard[1];\
 
    dp_easy[2] = easy[2] + max({easy[1], medium[1], hard[1]});
    dp_medium[2] = medium[2] + max({easy[1], medium[1], hard[1]});
    dp_hard[2] = hard[2] + max({easy[1], medium[1], hard[1]});
 
    dp_easy[3] = easy[3] + max({dp_easy[2], dp_medium[2], dp_hard[2]});
    dp_medium[3] = medium[3] + easy[2] + medium[1];
    dp_hard[3] = hard[3] + easy[1] + max({easy[2], medium[2], hard[2]});
    
    
    for (int i = 4; i <= N; ++i) {
        dp_easy[i] = easy[i] + max({dp_easy[i - 1], dp_medium[i - 1], dp_hard[i - 1]});
 
        dp_medium[i] = medium[i] + easy[i - 1] + dp_medium[i - 2];
 
        dp_hard[i] = hard[i] + easy[i - 1] + dp_easy[i - 2];
 
        dp_hard[i] = max(dp_hard[i], hard[i] + medium[i - 1] + easy[i - 2] + dp_medium[i - 3]);
        dp_hard[i] = max(dp_hard[i], hard[i] + hard[i - 1] + easy[i - 2] + dp_easy[i - 3]);
 
    }
 
    return max({dp_easy[N], dp_medium[N], dp_hard[N]});
}
 
int main() {
    int N;
    cin>>N;
    vector<int> easy(N+1), medium(N+1), hard(N+1);
 
    for(int i=1;i<=N;i++){
    	cin>>easy[i];
    }
 
    for(int i=1;i<=N;i++){
    	cin>>medium[i];
    }
 
    for(int i=1;i<=N;i++){
    	cin>>hard[i];
    }
    cout << "Maximum points: " << maximizePoints(N, easy, medium, hard) << endl;
 
    return 0;
}
 



// import java.util.Scanner;
// import java.util.Arrays;

// public class Main {
//     // Function to calculate the maximum points
//     public static int maximizePoints(int N, int[] easy, int[] medium, int[] hard) {
//         if (N == 0) return 0;

//         int[] dp_easy = new int[N + 1];
//         int[] dp_medium = new int[N + 1];
//         int[] dp_hard = new int[N + 1];

//         // starting first few index - No rule.
//         dp_easy[1] = easy[1];
//         dp_medium[1] = medium[1];
//         dp_hard[1] = hard[1];

//         dp_easy[2] = easy[2] + Math.max(Math.max(easy[1], medium[1]), hard[1]);
//         dp_medium[2] = medium[2] + Math.max(Math.max(easy[1], medium[1]), hard[1]);
//         dp_hard[2] = hard[2] + Math.max(Math.max(easy[1], medium[1]), hard[1]);

//         dp_easy[3] = easy[3] + Math.max(Math.max(dp_easy[2], dp_medium[2]), dp_hard[2]);
//         dp_medium[3] = medium[3] + easy[2] + medium[1];
//         dp_hard[3] = hard[3] + easy[1] + Math.max(Math.max(easy[2], medium[2]), hard[2]);

//         for (int i = 4; i <= N; ++i) {
//             dp_easy[i] = easy[i] + Math.max(Math.max(dp_easy[i - 1], dp_medium[i - 1]), dp_hard[i - 1]);

//             dp_medium[i] = medium[i] + easy[i - 1] + dp_medium[i - 2];

//             dp_hard[i] = hard[i] + easy[i - 1] + dp_easy[i - 2];

//             dp_hard[i] = Math.max(dp_hard[i], hard[i] + medium[i - 1] + easy[i - 2] + dp_medium[i - 3]);
//             dp_hard[i] = Math.max(dp_hard[i], hard[i] + hard[i - 1] + easy[i - 2] + dp_easy[i - 3]);
//         }

//         return Math.max(Math.max(dp_easy[N], dp_medium[N]), dp_hard[N]);
//     }

//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);
//         int N = scanner.nextInt();
//         int[] easy = new int[N + 1];
//         int[] medium = new int[N + 1];
//         int[] hard = new int[N + 1];

//         for (int i = 1; i <= N; i++) {
//             easy[i] = scanner.nextInt();
//         }

//         for (int i = 1; i <= N; i++) {
//             medium[i] = scanner.nextInt();
//         }

//         for (int i = 1; i <= N; i++) {
//             hard[i] = scanner.nextInt();
//         }

//         scanner.close();
//         System.out.println("Maximum points: " + maximizePoints(N, easy, medium, hard));
//     }
// }






// def maximizePoints(N, easy, medium, hard):
//     if N == 0:
//         return 0

//     dp_easy = [0] * (N + 1)
//     dp_medium = [0] * (N + 1)
//     dp_hard = [0] * (N + 1)

//     # starting first few index - No rule.
//     dp_easy[1] = easy[1]
//     dp_medium[1] = medium[1]
//     dp_hard[1] = hard[1]

//     dp_easy[2] = easy[2] + max(easy[1], medium[1], hard[1])
//     dp_medium[2] = medium[2] + max(easy[1], medium[1], hard[1])
//     dp_hard[2] = hard[2] + max(easy[1], medium[1], hard[1])

//     dp_easy[3] = easy[3] + max(dp_easy[2], dp_medium[2], dp_hard[2])
//     dp_medium[3] = medium[3] + easy[2] + medium[1]
//     dp_hard[3] = hard[3] + easy[1] + max(easy[2], medium[2], hard[2])

//     for i in range(4, N + 1):
//         dp_easy[i] = easy[i] + max(dp_easy[i - 1], dp_medium[i - 1], dp_hard[i - 1])
//         dp_medium[i] = medium[i] + easy[i - 1] + dp_medium[i - 2]
//         dp_hard[i] = hard[i] + easy[i - 1] + dp_easy[i - 2]
//         dp_hard[i] = max(dp_hard[i], hard[i] + medium[i - 1] + easy[i - 2] + dp_medium[i - 3])
//         dp_hard[i] = max(dp_hard[i], hard[i] + hard[i - 1] + easy[i - 2] + dp_easy[i - 3])

//     return max(dp_easy[N], dp_medium[N], dp_hard[N])


// if __name__ == "__main__":
//     N = int(input())
//     easy = [0] * (N + 1)
//     medium = [0] * (N + 1)
//     hard = [0] * (N + 1)

//     for i in range(1, N + 1):
//         easy[i] = int(input())

//     for i in range(1, N + 1):
//         medium[i] = int(input())

//     for i in range(1, N + 1):
//         hard[i] = int(input())

//     print("Maximum points:", maximizePoints(N, easy, medium, hard))









