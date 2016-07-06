  int integerBreak(int n) {
        return n < 4 ? n - 1 : n%3 == 0 ? pow(3,n/3) : pow(3,n/3-1) * (2+2*(n%3));
  }
  
  
  
  int integerBreak(int n) {
        int product=1, i=n;
        if(n==2)    return 1;
        if(n==3)    return 2;
        for(;i>4;i-=3){
            product*=3;    
        }
        product*=i;
        return product;
  }
  
  
  
