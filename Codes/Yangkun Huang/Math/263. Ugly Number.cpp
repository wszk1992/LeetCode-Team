    bool isUgly(int num) {
        while(num!=1){
            int tmp=num;
            if(num%5==0)
                num/=5;
            if(num%2==0)
                num/=2;
            if(num%3==0)
                num/=3;
            if(num==tmp)
                return false;
        }
        return true;
    }
