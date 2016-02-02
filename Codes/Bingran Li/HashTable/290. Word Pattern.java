public class Solution {
    public boolean wordPattern(String pattern, String str) {
        
        HashMap <Character,String> myMap = new HashMap <Character,String>();
        String [] myString = str.split(" ");
        
        if(pattern.length()!=myString.length)
            return false;
        
        for(int i=0;i<pattern.length();i++){
            if(!myMap.containsKey(pattern.charAt(i))){
                //didn't consider "ab" vs "dog dog" case----one value has more than one key
                if(myMap.containsValue(myString[i])) 
                    return false;
                else
                myMap.put(pattern.charAt(i),myString[i]); // miss myMap
            }
            else{ //there used to be a string case behind myMap, but cause compile error(cannot convert null to string)
                if(!(myMap.get(pattern.charAt(i))).equals(myString[i]))  // object has equals function
                    return false;
            }
        }
        
        return true;
        
    }
}