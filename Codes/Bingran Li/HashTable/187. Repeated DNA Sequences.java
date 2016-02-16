public class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        
        List<String> myList = new  ArrayList<String>(); // used to be List
        HashMap <String,Integer> myMap= new HashMap<String,Integer>();
        
        if(s.length()<10)
            return myList;
            
        for(int i=0;i<=s.length()-10;i++){
            String tem = s.substring(i,i+10);
            if(myMap.containsKey(tem)){
                if(myMap.get(tem)==1) {
                    myList.add(tem);
                    myMap.put(tem,2);
                }
            }
            else
                myMap.put(tem,1);
        }
        return myList;
    }
}