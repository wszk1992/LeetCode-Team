    // O(lgn*lgn)
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))  // INt_MIN=-INT_MIN
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;     // the thought here is to transform to positive number 
        long long dvd = labs(dividend);                           // why need to use long long
        long long dvs = labs(divisor);                            // The variable dividend and divisor might be INT_MIN
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;                       // binary search property shows here
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res;
    }
