    // method 1 iteration
    // T(i): unique numbers in [10^(i-1), 10^(i)]
    // U(i): nonunique numbers in [10^(i-1), 10^(i)]
    // U(i) = T(i-1)*i + U(i-1) *10  
    int countNumbersWithUniqueDigits(int n) {
        int totalNums=91, currUniqueNums=81, nonUniqueNums=9, rangeExt=90;
        if(n==0)    totalNums=1;
        if(n==1)    totalNums=10;
        for(int i=2;i<n;i++){
            rangeExt*=10;
            totalNums+=(rangeExt-(currUniqueNums*i+nonUniqueNums*10));
            nonUniqueNums=currUniqueNums*i+nonUniqueNums*10;
            currUniqueNums=rangeExt-nonUniqueNums;
        }
        return totalNums;
    }
    
    // method 2 combinatorics 
    // method 3 backtracking
