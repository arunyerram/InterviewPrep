// given two arrays find max sum possible and no two adjacent elements pick up from 2 arrays




        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        if (i > 2) {
            dp[i] = max(dp[i], dp[i - 3] + nums[i]);
        }
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}