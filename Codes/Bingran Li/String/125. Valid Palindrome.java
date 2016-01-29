public class Solution {
    public boolean isPalindrome(String s) {
        
        char [] myChar = s.toCharArray();
        ArrayList<Character> myList = new ArrayList<Character>();
        
        for(char element: myChar){
            if((element>='a'&&element<='z')||(element>='0'&&element<='9')){
                myList.add(element);
            }
            if(element>='A'&&element<='Z'){
                 element = (char)(element +32);
                 myList.add(element);
            }
        }
        if(myList.size()==0)
            return true;
        
        int i=0;
        while(i<(myList.size()+1)/2){ // ---------> IMPORTANT: it will round down when the length is even,so add one 
            if(myList.get(i)!=myList.get(myList.size()-1-i))
                return false;
            i++;
        }
        return true;
    }
}