public class Solution {
    public String longestCommonPrefix(String[] strs) {
        
        if(strs.length==0) // strs is array not string
            return  "";
        if(strs.length==1)
            return strs[0];
        String candidate = strs[0];
        for(int i=1;i<strs.length;i++){
            // compare each string with candidate string and get new candidate
           candidate = commonPrefix(candidate, strs[i] );
        }
        return candidate;
    }
    
    public static String commonPrefix(String string1, String string2){ // miss two String
        
        if(string1=="" || string2=="")
            return "";
        char [] char1 = string1.toCharArray(); // miss ()
        char [] char2 = string2.toCharArray();
        
        int i=0,j=0,count=0;
        
        while(i<char1.length && j<char2.length){
            
            if(char1[i]!=char2[j]){
                 break;
            }
            count++;
            i++;
            j++;
        }
       
        if(count == -1)
            return "";
        else
            return string1.substring(0,count); // the length is (endIndex-beginIndex)
    }
    // solution 2: 
    // use StringBuilder append and insert method which accept all data type
    // then use .toString() to return string
    
}