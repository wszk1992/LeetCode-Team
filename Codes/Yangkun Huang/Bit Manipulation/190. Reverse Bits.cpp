    // cheating method
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        for(int i=0;i<16;i++){
            if(b[i]!=b[31-i]){
                b.flip(i);
                b.flip(31-i);
            }
        }
        return b.to_ulong();
    }

    // a better method
    // for 8 bit binary number abcdefgh, the process is as follow:
    // abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
    
    // mainstream method
    uint32_t  reverseBits(uint32_t n) {
        uint32_t result= 0;
        for(int i=0; i<32; i++)
            result = (result<<1) + (n>>i &1);  // move bit by bit from right to left
        return result;
    }
