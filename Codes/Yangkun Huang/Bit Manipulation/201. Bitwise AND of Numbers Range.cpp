    // the result is either 0 or power of 2
    // lowest 1s will be set to 0 at each step, the final result is & of highest bits of m and n
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }

    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m!=n){
            m=m>>1;
            n=n>>1;
            ++i;        
        }
        return m<<i;
    }

    int rangeBitwiseAnd(int m, int n) {
        while(n > m)
            n = n & (n-1); // when loop ends, n has only 1 at highest bit or n=0
        return n;
    }
