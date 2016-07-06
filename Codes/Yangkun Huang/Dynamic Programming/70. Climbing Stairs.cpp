int climbStairs(int n) {
        int currWays=1,prevWays=0;
        int temp;
        for(int i=0;i<n;i++)
        {
            temp=currWays;
            currWays=prevWays+currWays;
            prevWays=temp;
        }
        return currWays;
    }