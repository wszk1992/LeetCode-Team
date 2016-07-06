    // method 1
    // i&(i-1) drops the lowest set of different bits
    // since i and i-1 are consecutive, they could be either different at last two digits or totally different at all digits
    vector<int> countBits(int num) {
        vector<int> bits(num+1, 0);
        for (int i = 1; i <= num; i++) 
            bits[i] = bits[i & (i-1)] + 1;
        return bits;
    }

    // method 2
    // n*2 means adding a 0 at rightmost, so 2n has the same bit 1 as n.
    vector<int> countBits(int num) {
   //if the ith number is even, the bit count is the same as i/2; otherwise the bit count is one more than i/2.
        vector<int> res(num+1,0);
        for(int i=1;i<=num;i++){
            res[i]= res[i/2];
            if (i%2==1) res[i]++;
        }
        return res;
    }
