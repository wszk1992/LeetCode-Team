      string convertToTitle(int n) {
        string res, tmp;
        while(n>0){
            tmp='A'+ --n%26;
            res=tmp+res;
            n/=26;
        }
        return res;
    }
