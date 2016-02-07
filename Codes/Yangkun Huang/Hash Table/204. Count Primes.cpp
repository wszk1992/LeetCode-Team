int countPrimes(int n) {
        if(n<3)
        return 0;
        int count=1;
        for(int i=3,j=3;i<n;i+=2)
        {
            for(j=3;j*j<=i;j+=2)
               if(i%j==0)
                break;
            if(j*j>i)
                count++;
        }
        return count;
    }