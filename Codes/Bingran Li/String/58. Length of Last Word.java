public class Solution {
    public int lengthOfLastWord(String s) {
        
        if(s.equals(""))
            return 0;
            
        s = s.trim(); // this api can remove space at front and end----> from 1ms to 0ms
        
        char [] myArray = s.toCharArray();
        int count =0;
    
        for(int i=myArray.length-1;i>-1;i--,count++){
            if(myArray[i]==' ')
                break;
        }
        
        return count;
        
    }
}