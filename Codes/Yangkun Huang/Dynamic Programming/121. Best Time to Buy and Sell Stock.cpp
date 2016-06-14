 int maxProfit(vector<int>& prices) { // minimum profit is 0
        int result=0,sum=0;              // maximum subarray could be nagetive    
        for(int i=1;i<prices.size();i++)
        {
            int diff=prices[i]-prices[i-1];
            sum=max(diff,sum+diff);
            result=max(result,sum);
        }
        return result;
    }