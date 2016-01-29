public class Solution {
    public int myAtoi(String str) {
        
        // fuck!!! do not want to do anymore
        /* judging sentences are complicated
        */
        str = str.trim();
        int i=0;
        int sum=0;
        boolean isMinus = false;
        while(i<str.length()){
            if(i==0 && str.charAt(i)=='-'){
                isMinus = true;
                i++;
                continue;
            }   
            if(i==0 && str.charAt(i)=='+') {
                i++;
                continue;
            }
                
            
            if(str.charAt(i)>'9' || str.charAt(i)<'0'){
                break;
            }
            
            if(isMinus){
                if((float)sum >= (float)((int)(str.charAt(i)-'0')+Integer.MIN_VALUE)/10){ 
                    // must divide it by 10 to compare, otherwise it will overflow
                    sum = sum*10 - (int)(str.charAt(i)-'0');
                }
                else 
                    return Integer.MIN_VALUE;
            }
            else{
                if( sum<=((Integer.MAX_VALUE-(int)(str.charAt(i)-'0'))/10)){
                     sum = sum*10 + (int)(str.charAt(i)-'0');
                }
                else 
                    return Integer.MAX_VALUE;
            }
            i++;
            
        }
   
        return sum;
    }
}