public class Solution {
    public boolean isHappy(int n) {
       
        // Didn't know how to express infinite loop---appear same value as before
        int num = n;
        boolean notHave=true;
        HashSet mySet = new HashSet();
        mySet.add(n);
        
        while(num!=1){
            int newNum=0;
            while(num>0){
                //newNum += Math.pow(num%10,2); // NOT LIKE THIS newNum + = Ma...(NO SPACE) 
                int tem=num%10; //-----------> IT REALLY MAKE A DIFFERENCE! (from 7ms to 5ms)
                newNum +=tem*tem;
                num = num/10;
            }
           notHave =  mySet.add(newNum); // false if contains
           if(!notHave)
                return false;
           num=newNum ;
        }
        return true;
    }
}