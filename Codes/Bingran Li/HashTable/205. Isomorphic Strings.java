public class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        // solution 1: 25%, a little slow
        if(s.length()!=t.length())
            return false;
        
        HashMap <Character, Character> myMap = new HashMap <Character, Character>();
        
        for(int i=0;i<s.length();i++){
            
            if(myMap.containsKey(s.charAt(i))==false && myMap.containsValue(t.charAt(i))==true) 
                return false;
            if(myMap.containsKey(s.charAt(i))==false && myMap.containsValue(t.charAt(i))==false) 
                myMap.put(s.charAt(i),t.charAt(i));
            if(myMap.containsKey(s.charAt(i))==true && myMap.get(s.charAt(i))!=t.charAt(i))
                return false;
            
        }
        return true;
        // solution 2: use two array to get two hashmap, map each other-----> it would be really fast
        
        
    }
}