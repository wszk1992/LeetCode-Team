	// method 1
	// buy[i] means profit of buy on day i, not max profit
	// sell[i] means profit of sell on day, not max profit
	int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
        return 0;
        vector<int> buy(prices.size());
        vector<int> sell(prices.size());
        buy[0]=-prices[0];
        int mProfit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(i==1)
                buy[i]= - prices[1];
            else
		// two situation
		// sell[i-2]-prices[i] means sold on day i-2 and buy on day i after cooldown                
 		// buy[i-1]-prices[i]+prices[i-1] means if day i-1 can buy, then day i can buy too. calculate the difference
		buy[i]=max(buy[i-1]-prices[i]+prices[i-1],sell[i-2]-prices[i]);
	    // two situation	
	    // buy[i-1]+prices[i] means buy on i-1 and sell on i
	    // sell[i-1]-prices[i-1]+prices[i] means if day i-1 can sell, then day i can sell too. calculate the difference
            sell[i]=max(buy[i-1]+prices[i],sell[i-1]-prices[i-1]+prices[i]);
            mProfit=max(mProfit,sell[i]);
        }
        return mProfit;
    }
    
    // method 2
    // the maxProfit for any sequence end with buy 
    // buy[i] = max(sell[i-2]-price, buy[i-1]) 
    // sell[i-2]-price -- buy on day i VS buy[i-1] -- buy before day i 
    // buy[i-1] means the maxProfit of buy at anytime before day i-1
    
    // the maxProfit for any sequence end with sell
    // sell[i] = max(buy[i-1]+price, sell[i-1]) sell on day i or not
    // buy[i-1]+price -- sell on day i VS sell[i-1] -- sell before day i
    // find max by sell on day i? sell on day i+1? sell on day i+2?...
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
    	// before the first day, didn't buy anything, profit must be INT_MIN(equal to buy something at expanse of INT_MAX)
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
