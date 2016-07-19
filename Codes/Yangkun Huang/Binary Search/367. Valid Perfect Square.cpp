    // tricky method
    bool isPerfectSquare(int num) {
        long r = num;       // here long is 64 bits as same as long long
        while (r*r > num)
            r = (r + num/r) / 2;  // mid of [num/r, r]
        return r*r == num;
    }
    
    // common method
    bool isPerfectSquare(int num) {
        if(num == 0) 
            return true;  // test case is lack of "num=0"
        long hi = 1, lo = 1;
        while(hi * hi < num) hi <<= 1;
        lo = hi >> 1;
        while(lo < hi) {
            long mid = (hi + lo) / 2;
            if(mid * mid >= num) 
                hi = mid;
            else 
                lo = mid + 1;
        }
        return hi * hi == num;
    }
