public class Solution {
    public int compareVersion(String version1, String version2) {
        
        // My solution: 
        /* 
        comparing based on digit numbers, which brings a lot of trouble
        front part is compared by adding, but pay attention that each one is a char
        back part is compared digit by digit, not elegant, so obeyed
        */
        // solution 1: this solution is the elegant way to implement my idea----> 92%
       
        int v1 = 0, v2=0;
        int i=0,j=0;
        // the whole structure is pretty good
        while (i<version1.length() || j<version2.length()){
            
            while( i<version1.length() && version1.charAt(i)!='.'){
                v1= v1*10 + Character.getNumericValue(version1.charAt(i)); // this expression is much better and is compatible 
                i++;
            }
            
            while( j<version2.length() && version2.charAt(j)!='.'){
                v2= v2*10 + version2.charAt(j)-'0' ; // another way for number operation
                j++;
            }
            
            if(v1<v2) return -1;
            if(v1>v2) return 1;
            
            i++;
            j++;
            v1=0;
            v2=0;
        }
        
        return 0;
       
        // solution 2: use appropriate APIs, it is simple-------> but slow, only 13%
        // we can parse string to int directly
        /*
        String [] string1 = version1.split("\\.");    // -------> why add \\
        String [] string2 = version2.split("\\.");
        
        int l1 = string1.length; // no () for array.length
        int l2 = string2.length;
        
        for(int i=0;i<(l1<l2? l2:l1);i++){
            
            int val1 = i<l1? Integer.parseInt(string1[i]) :0;
            int val2 = i<l2? Integer.parseInt(string2[i]) :0;
            
            if(val1<val2) return -1;
            if(val1>val2) return 1;
            
        }
        
        return 0;
        */
     
    }
}