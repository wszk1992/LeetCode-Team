    bool isPowerOfThree(int n) {
        if(!n)
            return false;
        double m=n;
        while(m-1){
            m/=3;
            if((int)m!=m)
                return false;
        }
        return true;
    }
    
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
    }
