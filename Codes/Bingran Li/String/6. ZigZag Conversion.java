public class Solution {
    public String convert(String s, int numRows) {
        
        // solution 1: too slow, Not using StringBuilder can only decrease a little time.but the problem come from using too much mod operation----3.5%---with 133ms
        /*
        if(numRows==1)
            return s;
        
        StringBuilder myString = new StringBuilder();
        char [] myArray = s.toCharArray();
        int modNumber = numRows*2-2;
        int i=1;
        while(i<=numRows){
            for(int m=0;m<myArray.length;m++){
                if((m+1) % modNumber==i||(m+1) % modNumber==2*numRows-i||(i==2 && (m+1) % modNumber ==0)){ // it is m+1, not m
                    myString.append(myArray[m]);
                }
            }
            i++;
        }
        return myString.toString();
        */
        // solution 2: -----86% with 7ms
        
        if(numRows==1)
            return s;
        StringBuilder sb = new StringBuilder();
        for(int i=1;i<=numRows;i++){
            // determine the step
            int step1 = (numRows - i)*2 ;
            int step2 = (i-1)*2;
            // special case
            if(i==1)
                step2=step1;
            if(i==numRows)
                step1=step2;
            // step begins with step1
            int step = step1;
            int m=i;
            while(m<=s.length()){
                sb.append(s.charAt(m-1));
                m=m+step;
                // alternate step
                step = step==step1? step2: step1;
            }
        }
        
        return sb.toString();
        
    }
}