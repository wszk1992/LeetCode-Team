    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){ // n & n-1 deliminate the lowest digit '1'
            n &= n - 1;
            ++ res;
        }
        return res;
    }
