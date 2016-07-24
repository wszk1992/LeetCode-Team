    // recursive
    double myPow(double x, int n) {
        if (n==0) 
            return 1;
        if (n==1) 
            return x;
        if (n==-1) 
            return 1/x;
        return myPow(x*x,n/2)*( !(n&1) ?1:n>0?x:1/x);
    }
    
    // iterative
    double myPow(double x, int n) {
        double ans = 1;
    	long p;
    	if (n < 0) {
    		p = n;  // if n=INT_MIN, then -n=n so that cannot use p=-n
    		p=-p;
    		x = 1 / x;
    	} 
    	else
    		p = n;
	while (p) {
		if (p & 1)   // every time p is odd, multply current x one more 
			ans *= x;
			x *= x;
			p >>= 1;
	}
	return ans;
    }
