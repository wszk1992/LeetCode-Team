  // solved by extending the method of "two transactions"
  // O(kn)
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(!k || len<2) return 0;
        if(len/2<=k){
            int sum=0;
            for(int i=1;i<len;i++){
                if(prices[i]-prices[i-1]>0)
                    sum+=(prices[i]-prices[i-1]);
            }
            return sum;
        }
        // if k is too large, claiming vector could result runtime error
        vector<int> buy(k,INT_MIN), sell(k,0);
        for(int i=0; i<len; ++i)
        {
            // buy[j] means profit with which the last operation is buying before day i
            // sell[j] means profit with which the last operation is selling before day i
            for(int j=k-1;j>0;j--){
                // compare selling on day i-1 and selling on day i(buy[j] here means j transactions buy at day i-1)
                sell[j]=max(sell[j],buy[j]+prices[i]);
                // compare buying on i-1 and buying on i
                buy[j]=max(buy[j],sell[j-1]-prices[i]);
            }
            sell[0]=max(sell[0],buy[0]+prices[i]);
            buy[0]=max(buy[0],-prices[i]);
        }
        return sell[k-1];
    }  
