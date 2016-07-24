class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) {
            return 1;
        }
        vector<int> dp(n, 0);
        int m = 9;
        int uni = 9;
        dp[0] = 10;
        int i = 0;
        for(i = 1; i < n; i++) {
            if(m == 0) {
                break;
            }
            uni *= m;
            m--;
            dp[i] = dp[i-1] + uni;
        }
        return dp[i - 1];
    }
};
