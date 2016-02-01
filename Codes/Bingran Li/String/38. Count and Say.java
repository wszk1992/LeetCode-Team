public class Solution {
    public String countAndSay(int n) {
        
        // what the hell.....not understanding at first
        // solution 1: -----> 80%
        if(n==1)
            return "1";
            
        String prev = countAndSay(n-1);
        // say the prev string
        char [] prevArray = prev.toCharArray();
        
        int outputNum =prevArray[0]-'0';
        int count =0;
        StringBuilder myString = new StringBuilder(); // good choice
        
        for(int i =0;i<prevArray.length;i++,count++){
            if(prevArray[i]-'0'!=outputNum){
                
                myString.append(count);
                myString.append(outputNum);
                outputNum = prevArray[i]-'0';
                count = 0; // used to be 1----> changes are likely to bring mistakes
            }
        }
         myString.append(count);
         myString.append(outputNum);
        
        return myString.toString();
        
        // solution 2: iterative -----refer HUANG
    }
}
