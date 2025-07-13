
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n + 1);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    dp[1] = 0;
    dp[2] = abs(cost[2] - cost[1]);
    cout<<dp[2]<<'\n';
    dp[3] = dp[2] + abs(cost[2]-cost[3]);
    cout<<dp[3]<<'\n';
    for (int i = 4; i <= n; ++i) {
        dp[i] = min(abs(cost[i] - cost[i - 1]) + dp[i - 1], abs(cost[i] - cost[i - 3]) + dp[i - 3]);
        cout<<dp[i];
        cout<<'\n';
    }

    cout << dp[n] << endl;
    return 0;
}


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] cost = new int[n + 1];
        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            cost[i] = sc.nextInt();
        }

        dp[1] = 0;
        dp[2] = Math.abs(cost[2] - cost[1]);

        for (int i = 3; i <= n; i++) {
            dp[i] = Math.min(Math.abs(cost[i] - cost[i - 1]) + dp[i - 1], Math.abs(cost[i] - cost[i - 3]) + dp[i - 3]);
        }

        System.out.println(dp[n]);
    }
}

