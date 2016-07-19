    bool isPowerOfTwo(int n) {
        bool meetOne=false;
        while(n){
            if(n & 1 ==1){
                if(meetOne)
                    return false;
                meetOne=true;
            }
            n=n>>1;
        }
        return meetOne;
    }
    
    // if n is power of two, n and n-1 differ in every bit
    bool isPowerOfTwo(int n) {
        return n>0 && ((n & (n-1)) == 0);
    }
    
    // the max power of two is 1073741824
    bool isPowerOfTwo(int n) {
        return n>0 && (1073741824 % n == 0);
    }
    
    bool isPowerOfTwo(int n) {
        if(n < 0) 
            return false;
        bitset<32> b(n);
        return b.count() == 1;
    }
