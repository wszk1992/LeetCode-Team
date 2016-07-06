    int maxProfit(vector<int>& prices) {
        // how to avoid multiple transactions: cur[2] is calculated basing on cur[1] which means sold before
        int states[2][4] = {INT_MIN, 0, INT_MIN, 0}; 
        int len = prices.size(), i, cur = 0, next =1;
        for(i=0; i<len; ++i)
        {
            // decide whether buy the 1st transaction or not
            states[next][0] = max(states[cur][0], -prices[i]);
            // keep the maximum profit of the 1st transaction
            states[next][1] = max(states[cur][1], states[cur][0]+prices[i]);
            // compare buy yesterday with buy today basing on profit of the first transaction
            states[next][2] = max(states[cur][2], states[cur][1]-prices[i]);
            // compare sell yesterday with sell today
            states[next][3] = max(states[cur][3], states[cur][2]+prices[i]);
            // reset and go to next day
            swap(next, cur);
        }
        // [cur][1] maximum profit by one trans [cur][2] maximum profit by two trans
        // return max(states[cur][1], states[cur][3]);
        return states[3];
    }

    // reduce space complexity
    int maxProfit(vector<int>& prices) {
        int states[4] = {INT_MIN, 0, INT_MIN, 0}; 
        int len = prices.size(), i, cur = 0, next =1;
        for(i=0; i<len; ++i)
        {
            states[3] = max(states[3], states[2]+prices[i]);
            states[2] = max(states[2], states[1]-prices[i]);
            states[1] = max(states[1], states[0]+prices[i]);
            states[0] = max(states[0], -prices[i]);
        }
        return states[3];
    }
