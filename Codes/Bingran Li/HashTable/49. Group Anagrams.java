public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        // beat 98%, write main function first, then writh tool function
        
        List<List<String>> result  = new ArrayList<List<String>> ();
        HashMap<String,Integer> myMap = new HashMap<String,Integer>();
        // the key of ate is aet, the value is its list index
        int listIndex=0;
        
        for(int i=0;i<strs.length;i++){
           
            String tem = convert(strs[i]);
           
            if(!myMap.containsKey(tem)){
                myMap.put(tem,listIndex);
                result.add(new ArrayList<String>()); // missing these two lines
                (result.get(listIndex)).add(strs[i]);
                listIndex++;
            }
            else{
                int temIndex = myMap.get(tem);
                (result.get(temIndex)).add(strs[i]);
            }
        }
        // last part is to sort inner list
        // **** cannot call function to swap, and have to use set() method******
        for(List<String> subList: result){
         
             int end=subList.size();
             while(end>1){
            
                for(int i=0;i<end-1;i++){
            
                String left = subList.get(i);
                String right = subList.get(i+1);
            
               if(left.compareTo(right)>0){
                     // maybe wrong
                    subList.set(i,right);
                    subList.set(i+1,left);
                }
             }
             end--;
          }
        
        }
        
        return result;
    }
    // given list of string, sort it
    /*
    public void sort(List<String> myList){
        // bubble sort :n2
        int end=myList.size();
        while(end>1){
            
          for(int i=0;i<end-1;i++){
            
            String left = myList.get(i);
            String right = myList.get(i+1);
            
            if(left.compareTo(right)<0){
                // maybe wrong
                 myList.set(i,right);
                 myList.set(i+1,left);
             }
          }
          end--;
       }
      
        
    }
    */
    // convert to key
    public String convert(String s){
        // string to array
        char [] myArray = s.toCharArray();
        // sort array
        Arrays.sort(myArray);
        // array to string
        String temS = new String(myArray); // ****** array to string, use this method*****
        return temS;
    }
}