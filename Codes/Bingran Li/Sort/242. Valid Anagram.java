public class Solution {
    public boolean isAnagram(String s, String t) {
        
        // solution 1: use HashMap----6%
        /*
        if(s.length()!=t.length())
            return false;
            
        HashMap <Character, Integer> myMap = new HashMap<Character, Integer>();
        
        for(int i =0;i<s.length();i++){
            if(myMap.containsKey(s.charAt(i))) 
                myMap.put(s.charAt(i),myMap.get(s.charAt(i))+1);
            else
                myMap.put(s.charAt(i),1);
        }
        
        for(int i=0;i<t.length();i++){
            if(myMap.containsKey(t.charAt(i))){
                myMap.put(t.charAt(i),myMap.get(t.charAt(i))-1);
                if(myMap.get(t.charAt(i))==0)
                    myMap.remove(t.charAt(i));
            }
        
        }
        
        if(myMap.size()!=0)
            return false;
        
        return true;
        */
        // solution two: build own map----5ms(88%)
        if(s.length()!=t.length())
            return false;
        char [] sArray = s.toCharArray(); // it is FASTER!
        char [] tArray = t.toCharArray();
        
        int [] myArray = new int[26];
        for(int i=0;i<s.length();i++){
            myArray[sArray[i]-'a']++; // if i use s.charAt(), it would be 12ms(27%)
            myArray[tArray[i]-'a']--;
           
        }
        for(int num:myArray){
            if (num!=0)
                return false;
        }
        
        return true;
    }
}