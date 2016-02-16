public class Solution {
    public int singleNumber(int[] nums) {
        
       // someone's solution: bitwise,linear time without extra memory
       // N^N=0;0^N=N

       int result=0;
       for(int i: nums){
           result = result^i;
       }
       return result;
       
       // solution 2: hashset
       /*
       HashSet <Integer>mySet = new HashSet<Integer>();
       for(int i: nums){
           if(!mySet.add(i)) 
                mySet.remove(i);
       }
        return mySet.iterator().next(); 
        */
    }
}