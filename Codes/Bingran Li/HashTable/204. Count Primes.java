public class Solution {
    public int countPrimes(int n) {
        
    // solution: follow the hint------decrease operation time step by step, see submissions
    
    if(n<=2)
        return 0;
        
    boolean [] myArray = new boolean[n];// change from int array to boolean array----->works, from 100ms to 50ms
    int count =0;
    
    for(int p=3;p*p<n;p=p+2){ // avoid using function sqrt()
        for(int m=p*p;m<n;m=m+2*p){ // start from q*q
            if(myArray[m]==false) // ---->not improve
                count++;
            myArray[m]=true;
        }
        
    }  
   
    return n-1-count-(n-1)/2;   
        
        
    }
}