// how to write state equation
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 0) 
            return -1;//cannot make change with 0 coins
        if(amount == 0) 
            return 0;//can always make change without any coins
        int dp[amount+1];
        dp[0] = 0;//base case: when amount = 0
        for(int amt = 1; amt <= amount; amt++){
            dp[amt] = -1;
            for(int i = 0; i < n; i++){
                if(amt - coins[i] >= 0 && dp[amt-coins[i]] != -1){
                    if(dp[amt] == -1) 
                        dp[amt] = dp[amt-coins[i]]+1;
                    else 
                        dp[amt] = min(dp[amt], dp[amt-coins[i]]+1);
                }
            }
        }
        return dp[amount];
    }
