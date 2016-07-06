  // need to specify subproblem division
  // method 1
  int numDecodings(string s) {
    int minusTwo, minusOne = 1, ways = 0;
    char pre = '3'; // any except '1' and '2'
    for (char cur : s) {
        ways = 0;
        if (cur > '0') // decode 1 digit
            ways += minusOne;
        if (pre == '1' || (pre == '2' && cur <= '6')) // decode 2 digits
            ways += minusTwo;
        if (ways == 0) // prune
            break;
        minusTwo = minusOne;
        minusOne = ways;
        pre = cur;
    }
    return ways;
  }
  
  
  // method 2 own method
  // problem: n-1 -> n-2 -> n-3 ->...
  // solution: n-3 -> ... has been solved in f(n-1) case
  int numDecodings(string s) {
    int currWays=0, onePrevWays=1, twoPrevWays=0;
    char prev='9';
      for(auto c:s){
        if(c=='0'){
            if(prev=='0'||prev>'2')
                return 0;
            currWays=twoPrevWays;
        }
        else{
            if((c>'0' && c<'7') && (prev>'0' && prev<'3') || ((prev=='1')&& (c>'6') ))
                currWays=onePrevWays+twoPrevWays;
            else
                currWays=onePrevWays;
        }
        prev=c;
        twoPrevWays=onePrevWays;
        onePrevWays=currWays;
    }
    return currWays;
    }
