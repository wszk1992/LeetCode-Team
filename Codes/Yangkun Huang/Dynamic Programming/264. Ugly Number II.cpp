    // traverse every power of 2, 3 and 5
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);           // check and record each multiple of 2, 3 and 5
        k[0] = 1;
        for(int i  = 1; i < n ; i ++){
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2)
                t2++; 
            if(k[i] == k[t3]*3) 
                t3++;
            if(k[i] == k[t5]*5) 
                t5++;
        }
        return k[n-1];
    }
    
    // static version 4ms
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        static int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        static vector<int> k(1,1);
        int i=k.size();
        while(n>i){
            k.push_back( min(k[t2]*2,min(k[t3]*3,k[t5]*5)));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
            i++;
        }
        return k[n-1];
    }
